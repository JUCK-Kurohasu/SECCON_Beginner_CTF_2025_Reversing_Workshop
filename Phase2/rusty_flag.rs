use std::io::{self, Write};

const MAGIC_NUMBER: u32 = 0x13371337;

fn transform_char(c: char, index: usize) -> char {
    let shift = ((MAGIC_NUMBER >> (index % 4 * 8)) & 0xFF) as u8;
    let mut byte = c as u8;
    byte = byte.wrapping_add(shift);
    byte = byte ^ 0xAA;
    byte as char
}

fn check_flag(input: &str) -> bool {
    // Expected transformed result
    let expected = [
        0xE8, 0x9F, 0x8B, 0x85, 0xF7, 0xDB, 0x88, 0xC4, 0x9F, 0xCE,
        0xD7, 0xC4, 0x9C, 0xCE, 0xD7, 0x93, 0xCE, 0x82, 0xD6, 0xCD,
        0xC4, 0x96, 0xD6, 0xF6
    ];
    
    if input.len() != expected.len() {
        return false;
    }
    
    for (i, c) in input.chars().enumerate() {
        let transformed = transform_char(c, i) as u8;
        if transformed != expected[i] {
            return false;
        }
    }
    
    true
}

fn print_banner() {
    println!("====================================");
    println!("   Rusty Flag Checker v1.0");
    println!("====================================");
    println!("Powered by Rust 🦀\n");
}

fn main() {
    print_banner();
    
    print!("Enter the flag: ");
    io::stdout().flush().unwrap();
    
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    
    let input = input.trim();
    
    if check_flag(input) {
        println!("\n✓ Correct! You found the flag!");
    } else {
        println!("\n✗ Incorrect. Keep trying!");
    }
}