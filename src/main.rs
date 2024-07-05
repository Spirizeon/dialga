const _VERSION_NUM: &str = "0.0.1";
mod init;
mod hash;
//mod compress;
use std::env;
// use std::fs;
fn main() {
    let args: Vec<String> = env::args().collect();
    let argc = args.len();
    if argc < 2 {
        println!("Dialga is under dev");
    }
    else if &args[1] == "init"{
        init::init();        
    }
    else if &args[1] == "status"{

    }
    else if &args[1] == "commit"{
        //create a blob and return blob path
        hash::hash("sample");
        //remove the compress function for now

    }
    else {
        
    }
}
