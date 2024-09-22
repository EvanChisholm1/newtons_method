let mesage = "Hello, World!"
let () = print_endline mesage

let rec poly (coeff: float list) (degree: float) (x: float) = 
  match coeff with
  | [] -> 0.0
  | c :: r -> (c *. x ** degree) +. poly r (degree -. 1.0) x;;

let y = poly [1.0; 1.0; 0.0; 0.0] 3.0 2.0;;

Printf.printf "%f" y;;
