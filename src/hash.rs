extern crate sha2;
use std::fs;
use sha2::{Sha256,Digest};
use std::path::Path;
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
    

    //step-1 write hashed content to tree file on every blob
    let _ = fs::write(".dlgx/objects/temptree","fkcthisshit");
    //step-2 read the treefile
    let treedata = fs::read_to_string(".dlgx/objects/temptree").expect("could not read tree file");
    //step-3 hash the contents
    let mut hasher2 = Sha256::new();
    hasher2.update(treedata.as_bytes());
    let treename = hasher2.finalize();
    let treename = format!("{:x}",result);
    //step-4 rename the file
    let newname = String::from(".dlgx/objects/") + &treename;
    let _ = fs::rename(".dlgx/objects/temptree",newname);

}
