use std::fs;
use std::fs::File;

pub fn createindex(){
   let _ = File::create(".dlgx/index"); 
}

pub fn readindex(){
   let data  = fs::read_to_string(".dlgx/index");
   for element in data.expect("could not split file").split("\n") {
        println!("<added> {element}");
    }
}

pub fn writeindex(argument:&str){
    let _ file = File::open(".dlgx/index");
    fs::write(".dlgx/index",argument); 
}

