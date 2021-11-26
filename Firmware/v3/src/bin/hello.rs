#![no_main]
#![no_std]

use rust_firmware_hello_world as _; // global logger + panicking-behavior + memory layout

#[cortex_m_rt::entry]
fn main() -> ! {
    defmt::println!("Hello, world!");

    rust_firmware_hello_world::exit()
}
