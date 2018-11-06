use std::collections::HashMap;
use std::io;


fn make_set(index: usize, parents: &mut [usize], size: &mut[usize]) {
    parents[index] = index;
    size[index] = 1;
}

fn find_set(index: usize, parents: &mut [usize]) -> usize {
    if index == parents[index] {
        return index;
    }
    parents[index] = find_set(parents[index], parents);
    parents[index]
}

fn union_sets(first: usize, second: usize, parents: &mut Vec<usize>, size: &mut [usize]) {
    let mut par1 = find_set(first, parents);
    let mut par2 = find_set(second, parents);

    if par1 != par2 {
        if size[par1] < size[par2] {
            let tmp = par1;
            par1 = par2;
            par2 = tmp;
        }
        parents[par2] = par1;
        size[par1] += size[par2];
    }
    println!("{}", size[par1]);
}

fn main() {

    let stdin = io::stdin();
    let mut first_line= String::new();
    stdin.read_line(&mut first_line);
    let nr_testcases = first_line[..first_line.len()-1].parse::<usize>().unwrap();


    for _ in 0..nr_testcases {

        let mut name_map: HashMap<String, usize> = HashMap::new();
        let mut number_of_connections_str= String::new();
        stdin.read_line(&mut number_of_connections_str);
        let number_of_connections = number_of_connections_str[..number_of_connections_str.len()-1].parse::<usize>().unwrap();
        let mut counter:usize = 0;
        let mut parents:Vec<usize> = Vec::with_capacity(number_of_connections*2);
        let mut size:Vec<usize> = Vec::with_capacity(number_of_connections*2);



        for _ in 0 .. number_of_connections {
            let mut connection = String::new();
            stdin.read_line(&mut connection);
            let names:Vec<&str> = connection.split_whitespace().map(| name| {
                if !name_map.contains_key(name) {
                    name_map.insert(String::from(name), counter);
                    parents.push(counter);
                    size.push(1);
                    counter += 1;
                }
                name
            }).collect();
            unsafe {
                union_sets(*name_map.get(*names.get_unchecked(0)).unwrap(),
                           *name_map.get(*names.get_unchecked(1)).unwrap()
                            ,&mut parents, &mut size);
            }
        }

    }
}
