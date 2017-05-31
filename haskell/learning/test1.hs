double x = x * 2
double2 x y = double x + double y
double_small x = if x > 100
                    then x
                    else x*2
double_small' x = (double_small x) + 1


length' xs = sum [1 | _ <- xs]
