let mesage = "Hello, World!"
let () = print_endline mesage

let rec poly (coeff: float list) (x: float) = 
  match coeff with
  | [] -> 0.0
  | c :: r -> (c *. x ** float_of_int (List.length r)) +. poly r x;;

let y = poly [1.0; 1.0; 0.0; 0.0] 2.0;;

Printf.printf "%f" y;;
