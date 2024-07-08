/* 
#read .commit for file name and hash
  dialga   main  #find hashfile
  dialga   main  #create new file with file name, and contents
  dialga   main  #decompress contents #read .commit for file name and hash
  dialga   main  #find hashfile
  dialga   main  #create new file with file name, and contents
  dialga   main  #decompress contents
*/
use std::fs;
use std::fs::File;
use std::fs::OpenOptions;

use miniz_oxide::inflate::decompress_to_vec;

pub fn restore(hash_name: &str){
    let commit_data = fs::read_to_string(".dlgx/objects/.commit")
    .expect("could not read commit file");
    let parts: Vec<&str> = commit_data.split("|").collect();
    let file_path = parts[1];
    let hash_path = String::from(".dlgx/objects/")+ &hash_name[0..2] + "/" + &hash_name[2..]; 
    //this is a valid path ✅ 

    let file_data = fs::read(hash_path).expect("could not read hash data");
    let decompressed = decompress_to_vec(&file_data).expect("failed to decompress");
    let file_data_string = String::from_utf8(decompressed).expect("failed to convert into string");

    // Check if the file exists
    let file_exists = std::path::Path::new(&file_path).exists();
    
    if file_exists {
        // Open the file in write mode
        let _ = OpenOptions::new()
            .write(true)
            .append(true) // append to existing file
            .open(&file_path);
        
        // Write to the file
        fs::write(file_path,file_data_string).expect("could not write file");
    } else {
        // Create a new file and open it in write mode
        let _ = File::create(&file_path);
        
        // Write to the file
        fs::write(file_path,file_data_string).expect("file created but could not write");
    }
}
