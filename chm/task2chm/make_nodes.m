function [v_x] = make_nodes(n)
    # j = 0, 2*n - 1
    for jj = 1:2 * n
        v_x(jj) = ( pi * (jj-1) ) / n;
    endfor
endfunction