extern crate sha2;
extern crate whoami;
extern crate miniz_oxide;
use std::fs;
use std::fs::OpenOptions;
use std::io::Write;
use sha2::{Sha256,Digest};
use miniz_oxide::deflate::compress_to_vec;



pub fn hash(file_name: &str,commit_msg: &str){
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


    let byted_data = data.as_bytes();
    let compressed_data = compress_to_vec(byted_data,6);

    let _ = fs::write(blob_path,compressed_data);

    //step-2 write the treefile
    let mut file = OpenOptions::new()
    .write(true)
    .append(true)
    .open(".dlgx/objects/.commit")
    .expect("Failed to open file");

    let user = whoami::username();

    if let Err(e) = writeln!(file, "{}|{}|{}|{}",user,file_name,commit_msg,&hash_hex) {
        println!("Failed to write to file: {}", e);
    }

} 
