use std::collections::HashMap;
use std::io;


fn make_set(name: &str) {}

fn main() {
    let mut name_map: HashMap<String, u32> = HashMap::new();
    let stdin = io::stdin();
    let mut first_line= String::new();
    stdin.read_line(&mut first_line);
    let nr_testcases = first_line[..first_line.len()-1].parse::<usize>().unwrap();

    for _ in 0..nr_testcases {

        let mut number_of_connections_str= String::new();
        stdin.read_line(&mut number_of_connections_str);
        let number_of_connections = number_of_connections_str[..number_of_connections_str.len()-1].parse::<usize>().unwrap();

        for _ in 0 .. number_of_connections {
            let mut connection = String::new();
            stdin.read_line(&mut connection);
            let names:Vec<&str> = connection.split_whitespace().map(| name| {
                if !name_map.contains_key(name) {
                   make_set(name);
                }
                name
            }).collect();
            union_sets(names.get_unchecked(0), names.get_unchecked(1))
            println!("Hej")
        }
    }
}

