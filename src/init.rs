use std::fs;

pub fn init(){
    let _ = fs::create_dir(".dlgx");
    let dlgx_contents = ["objects","refs","refs/heads"];
    for element in dlgx_contents {
        let path_ex = String::from(".dlgx/") + element;
        let _ = fs::create_dir(path_ex);
    }
    // make index file now
    let _ = fs::write(".dlgx/index","");
    println!("===================================");
    println!("dialga: your 💖 for git, debloated");
    println!("docs @ https://spirizeon.github.io/dialga");
    println!("repo initialised with (.dlgx)!");
    println!("===================================");
}
    

