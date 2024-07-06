const _VERSION_NUM: &str = "0.0.1";
mod init;
mod hash; //create blobs and make tempo tree
mod tree; //create tree object and delete tempo tree

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
        hash::hash("sample");
        hash::hash("sample2");
        hash::hash("sample3");
        tree::hash();
        //remove the compress function for now

    }
    else {
        
    }
}
