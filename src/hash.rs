extern crate sha2;
use std::fs;
use sha2::{Sha256,Digest};

pub fn hash(file_name: &str) {
    //create blobs
    let data = fs::read_to_string(file_name)
        .expect("could not read file");
    let mut hasher = Sha256::new();
    hasher.update(data.as_bytes());
    let result = hasher.finalize();
    let hash_hex = format!("{:x}",result);
    let blob_dir_path = String::from(".dlgx/") + &hash_hex[0..2];
    let _ = fs::create_dir(blob_dir_path);
    let blob_path = String::from(".dlgx/") + &hash_hex[0..2] + "/" + &hash_hex[2..];
    let _ = fs::write(blob_path,"");
    //return file path for compression
}


