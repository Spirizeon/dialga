use std::io::prelude::*;
use flate2::Compression;
use flate2::write::ZlibEncoder;
use std::fs;
//take blob path as argument
pub fn compress(blob: &str) -> &str {
    let data = fs::read_to_string(blob)
        .expect("should have been able to read the file");
    let mut e = ZlibEncoder::new(Vec::new(), Compression::default());
    //encode the data
    e.write_all(data).unwrap();
    let compressed_bytes = e.finish().unwrap();
    //convert vec<u8> -> string
    let compressed_string = base64::encode(&compressed_bytes);
    //return compressed contetn
    return compressed_string;
}

