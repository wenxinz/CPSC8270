%{
// Flex handles ambiguity by matching longest string;
// in case of tie, it matches the first one.

#include <iostream>
#include <string>
#include <stack>

std::stack<std::string> letters;

%}
letter      [a-zA-Z]
blank       [ ]

%%
{blank}      { letters.push(" ");                            }
a            { letters.push(u8"\u0250");              }
b            { letters.push(u8"\u0071");              }
c            { letters.push(u8"\u0254");              }
d            { letters.push(u8"\u0070");              }
e            { letters.push(u8"\u01DD");              }
f            { letters.push(u8"\u025F");              }
g            { letters.push(u8"\u0253");              }
h            { letters.push(u8"\u0265");              }
i            { letters.push(u8"\u0131");              }
j            { letters.push(u8"\u027E");              }
k            { letters.push(u8"\u029E");              }
l            { letters.push(u8"\u006C");              }
m            { letters.push(u8"\u026F");              }
n            { letters.push(u8"\u0075");              }
o            { letters.push(u8"\u006F");              }
p            { letters.push(u8"\u0064");              }
q            { letters.push(u8"\u0062");              }
r            { letters.push(u8"\u0279");              }
s            { letters.push(u8"\u0073");              }
t            { letters.push(u8"\u0287");              }
u            { letters.push(u8"\u006E");              }
v            { letters.push(u8"\u028C");              }
w            { letters.push(u8"\u028D");              }
x            { letters.push(u8"\u0078");              }
y            { letters.push(u8"\u028E");              }
z            { letters.push(u8"\u007A");              }
A            { letters.push(u8"\u2200");              }
B            { letters.push(u8"\u0412");              }
C            { letters.push(u8"\u0186");              }
D            { letters.push(u8"\u15E1");              }
E            { letters.push(u8"\u018E");              }
F            { letters.push(u8"\u2132");              }
G            { letters.push(u8"\u2141");              }
H            { letters.push(u8"\u0048");              }
I            { letters.push(u8"\u0049");              }
J            { letters.push(u8"\u017F");              }
K            { letters.push(u8"\u22CA");              }
L            { letters.push(u8"\u2142");              }
M            { letters.push(u8"\u0057");              }
N            { letters.push(u8"\u004E");              }
O            { letters.push(u8"\u004F");              }
P            { letters.push(u8"\u0500");              }
Q            { letters.push(u8"\u038C");              }
R            { letters.push(u8"\u1D1A");              }
S            { letters.push(u8"\u0053");              }
T            { letters.push(u8"\u22A5");              }
U            { letters.push(u8"\u2229");              }
V            { letters.push(u8"\u039B");              }
W            { letters.push(u8"\u004D");              }
X            { letters.push(u8"\u0058");              }
Y            { letters.push(u8"\u2144");              }
Z            { letters.push(u8"\u005A");              }
1            { letters.push(u8"\u21C2");              }
2            { letters.push(u8"\u218A");              }
3            { letters.push(u8"\u218B");              }
4            { letters.push(u8"\u07C8");              }
5            { letters.push(u8"\u03DA");              }
6            { letters.push(u8"\u0039");              }
7            { letters.push(u8"\u3125");              }
8            { letters.push(u8"\u0038");              }
9            { letters.push(u8"\u0036");              }
0            { letters.push(u8"\u0030");              }
&            { letters.push(u8"\u214B");              }
_            { letters.push(u8"\u203E");              }
\?           { letters.push(u8"\u00BF");              }
!            { letters.push(u8"\u00A1");              }
\"           { letters.push(u8"\u201E");              }
'            { letters.push(u8"\u002C");              }
`            { letters.push(u8"\u002C");              }
\.           { letters.push(u8"\u02D9");              }
,            { letters.push(u8"\u0027");              }
;            { letters.push(u8"\u061B");              }
\n           { while(!letters.empty()){
  	             std::cout << letters.top();
  	             letters.pop();
               }
               std::cout << std::endl;
             }
.            {}
%%
int yywrap() {
  yylex_destroy(); 
  return 1; 
}

