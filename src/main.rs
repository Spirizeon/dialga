const _VERSION_NUM: &str = "0.0.1";
mod init;
mod hash; //create blobs and make tempo tree
mod restore;
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
        hash::hash("sample","what");
        hash::hash("sample2","in the world");
        hash::hash("sample3","is this dialga");
        //remove the compress function for now
        //
    }
    else if &args[1] == "restore"{
        restore::restore("ae063dc00b1765ae65102006ee1f7f826244b4639a406ffcdf0a15ef858b2aa3");
    }
    else {
        
    }
}
