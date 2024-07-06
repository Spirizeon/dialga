extern crate sha2;
use std::fs;
use std::fs::OpenOptions;
use std::io::Write;
use sha2::{Sha256,Digest};


pub fn hash(file_name: &str){
    //create blobs
    let data = fs::read_to_string(file_name)
        .expect("could not read file");
    let mut hasher = Sha256::new();
    hasher.update(data.as_bytes());
    let result = hasher.finalize();
    
    let hash_hex = format!("{:x}",result);


    let blob_dir_path = String::from(".dlgx/objects/") + &hash_hex[0..2];
    let _ = fs::create_dir(blob_dir_path);
    let blob_path = String::from(".dlgx/objects/") + &hash_hex[0..2] + "/" + &hash_hex[2..];
    let _ = fs::write(blob_path,"");

    //step-2 write the treefile
    let mut file = OpenOptions::new()
    .write(true)
    .append(true)
    .open(".dlgx/objects/temptree")
    .expect("Failed to open file");

    if let Err(e) = writeln!(file, "blob {}", hash_hex) {
        eprintln!("Failed to write to file: {}", e);
    }
    //step-3 hash the contents
    //let hash_tree_hex = hash(".dlgx/objects/temptree");
    //step-4 rename the file
    //let newname = String::from(".dlgx/objects/") + hash_tree_hex;
    //let _ = fs::rename(".dlgx/objects/temptree",newname);
    //step-5 done!

} 
