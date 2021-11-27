#![no_main]
#![no_std]

use nixie_clock as _; // global logger + panicking-behavior + memory layout
use nixie_clock::hal;

use hal::prelude::*;
use hal::stm32;

#[cortex_m_rt::entry]
fn main() -> ! {
    defmt::println!("Blinky!");

    let dp = stm32::Peripherals::take().expect("Cannot take peripherals");
    let mut rcc = dp.RCC.constrain();
    let mut delay = dp.TIM16.delay(&mut rcc);

    let gpiob = dp.GPIOB.split(&mut rcc);
    let mut led = gpiob.pb0.into_push_pull_output();

    loop {
        led.toggle().unwrap();
        delay.delay(500.ms());
    }
}
