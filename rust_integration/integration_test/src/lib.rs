#![no_std]
#![feature(lang_items)]
#![feature(core_intrinsics)]

use core::panic::PanicInfo;

#[lang = "eh_personality"]
extern "C" fn eh_personality() {}

pub extern "C" fn add(a: i32, b: i32) -> i32 {
    a + b
}



#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}