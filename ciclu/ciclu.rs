use std::collections::VecDeque;
use std::fs;

const INPUT_FILE: &str = "ciclu.in";
const OUTPUT_FILE: &str = "ciclu.out";

fn read() -> (i64, i64, Vec<Vec<(i64, i64)>>) {
    let contents: String =
        fs::read_to_string(INPUT_FILE).expect("Something went wrong reading the file");
    let trimmed = contents.trim();

    let vec = trimmed
        .split_whitespace()
        .map(|x| x.parse::<i64>().expect("parse error"))
        .collect::<Vec<i64>>();

    let (n, m) = (vec[0], vec[1]);
    let mut graph: Vec<Vec<(i64, i64)>> = (0..n + 1).map(|_| Vec::new()).collect();
    for i in 0..m {
        let (a, b, c) = (
            vec[i as usize * 3 + 2],
            vec[i as usize * 3 + 3],
            vec[i as usize * 3 + 4],
        );
        graph[a as usize].push((b, c * 100));
    }
    for i in 1..n + 1 {
        graph[0].push((i, 0));
    }
    return (n, m, graph);
}

fn neg_cycle(v: i64, n: i64, graph: &Vec<Vec<(i64, i64)>>) -> bool {
    let mut queue: VecDeque<i64> = VecDeque::new();
    let mut ap: Vec<i64> = vec![0; n as usize + 1];
    let mut dp: Vec<i64> = vec![0x3f3f3f3f; n as usize + 1];
    let mut inq: Vec<bool> = vec![false; n as usize + 1];

    queue.push_back(0);
    dp[0] = 0;

    let mut x: i64;

    while !queue.is_empty() {
        x = *queue.front_mut().unwrap();
        queue.pop_front();
        inq[x as usize] = false;

        for j in &graph[x as usize] {
            let y = j.0;
            let w = j.1;
            if dp[y as usize] > dp[x as usize] + w - v {
                dp[y as usize] = dp[x as usize] + w - v;
                if inq[y as usize] == false {
                    ap[y as usize] += 1;
                    if ap[y as usize] == n {
                        return true;
                    }
                    queue.push_back(y);
                    inq[y as usize] = true;
                }
            }
        }
    }
    return false;
}

fn solve(n: i64, graph: Vec<Vec<(i64, i64)>>) -> f64 {
    let mut left: i64 = 0;
    let mut right: i64 = 10000000;
    let mut mid: i64;

    while left <= right {
        mid = (left + right) / 2;
        let res = neg_cycle(mid, n, &graph);
        if res == false {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left as f64 / 100.0;
}

fn main() {
    let (n, _, graph) = read();
    let result = solve(n, graph);
    fs::write(OUTPUT_FILE, result.to_string()).expect("Unable to write file");
}
