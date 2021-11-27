#![no_main]
#![no_std]

use nixie_clock as _; // global logger + panicking-behavior + memory layout

#[cortex_m_rt::entry]
fn main() -> ! {
    defmt::println!("Hello, world!");

    nixie_clock::exit()
}
