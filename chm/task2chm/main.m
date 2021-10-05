n = 14;
#
#func = @(x) (exp(sin(x) + cos(x)));
func = @(x) (3.*cos(15.*x));
#func = @(x) log(x.+2);
#func = @(x) (1+25*x.^2).^-1;
#func = @(x) (sin(x));
#
v_x = make_nodes(n)
v_y = func(v_x)
m = 50;
drawX = make_nodes(m);
drawY = func(drawX)
#
trigonPolinom = @(t) TrigonInterp(v_y, t, n);
trigonPolinY = trigonPolinom(drawX)
#
plot(drawX, drawY, "-g", drawX, trigonPolinY, "--b");
xlabel("x");
ylabel("y");
legend("func", "trigon");