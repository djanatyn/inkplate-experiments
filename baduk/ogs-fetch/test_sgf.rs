use sgf_parse::{parse, go::Prop};

fn main() {
    let sgf = "(;FF[4]GM[1];B[pd](;W[dp])(;W[pp]))";
    let game_trees = parse(sgf).expect("Failed to parse");
    let game_tree = game_trees.first().expect("No game tree");
    let root_node = game_tree.as_go_node().expect("Not a go node");
    
    println!("Exploring main variation:");
    for (i, node) in root_node.main_variation().enumerate() {
        println!("Node {}: {:?} properties", i, node.properties().count());
        for prop in node.properties() {
            println!("  - {:?}", prop);
        }
    }
}
