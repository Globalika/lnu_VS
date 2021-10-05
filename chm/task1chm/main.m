#input
a = 0;b = 2*pi;
n = input("n=");

#func
#func = @(x) abs(x);
#func = @(x) (1+25*x.^2).^-1;
#func = @(x) log(x.+2);
#func = @(x) (exp(sin(x) + cos(x)));
#func = @(x) (3.*cos(15.*x));
func = @(x) (sin(x));
#nodes
v_x = 0;v_y = 0;
if(input("1:Equally spaced|2:Chebushev spaced : ") == 1)
  v_x = make_nodes(1,a,b,n);
  v_y = func(v_x);
else
  v_x = make_nodes(2,a,b,n);
  v_y = func(v_x);
endif

#interp
pLagr = lagrange (v_x, v_y)###
pNewt = newton (v_x, v_y)###
#x?

x = 0.5


fx1 = polyval(pLagr, x)
res1 = abs(fx1 - func(x))

fx2 = polyval(pNewt, x)
res2 = abs(fx2 - func(x))

#plot
X = linspace(a,b,100);
YFunc = func(X);
YLagr = polyval(pLagr, X);
YNewt = polyval(pNewt, X);
#
plot(X,YFunc,'b')###
title ("Task 1");
hold on;
plot(X,YLagr,'r',"linestyle",'--')
hold on;
plot(X,YNewt,'g')
xlabel ("x");
ylabel ("y");
legend ("func","lagr","newt");

