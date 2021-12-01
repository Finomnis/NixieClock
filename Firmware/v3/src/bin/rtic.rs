#![no_main]
#![no_std]

use nixie_clock as _; // global logger + panicking-behavior + memory layout
use nixie_clock::hal;

use hal::gpio::gpiob::PB0;
use hal::gpio::{GpioExt, Output, PushPull};
use hal::prelude::*;
use hal::rcc::RccExt;
use hal::stm32;
use hal::timer::{Timer, TimerExt};

use rtic::app;

#[app(device = nixie_clock::hal::stm32, peripherals = true)]
const APP: () = {
    struct Resources {
        timer: Timer<stm32::TIM16>,
        led: PB0<Output<PushPull>>,
    }

    #[init]
    fn init(ctx: init::Context) -> init::LateResources {
        // enable dma clock during sleep, otherwise defmt doesn't work
        ctx.device.RCC.ahbenr.modify(|_, w| w.dmaen().set_bit());

        defmt::println!("Rtic Blinky!");

        // Initialize GPIOs
        let mut rcc = ctx.device.RCC.constrain();
        let gpiob = ctx.device.GPIOB.split(&mut rcc);
        let led = gpiob.pb0.into_push_pull_output();

        // Initialize timers
        let mut timer = ctx.device.TIM16.timer(&mut rcc);
        timer.start(1.hz());
        timer.listen();

        init::LateResources { timer, led }
    }

    #[task(binds = TIM16, resources = [led, timer])]
    fn timer_tick(ctx: timer_tick::Context) {
        ctx.resources.led.toggle().unwrap();
        ctx.resources.timer.clear_irq();
    }
};
