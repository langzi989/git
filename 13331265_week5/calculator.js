function runOnBeforeLoad() {
	alert("注意!\n1.当输入正负号时必须将符号用()括起来，否则格式错误\n2.重新输入之前需要清零");
}
function update(expresstion) {
	document.getElementById("input_field").value = expresstion;
}

function input(num) {
	var expresstion = document.getElementById("input_field").value + num;
	update(expresstion);
}


function reset() {
	var expresstion = "";
	update(expresstion);
}

function back() {
	var expresstion = document.getElementById("input_field").value;
	expresstion = expresstion.substring(0, expresstion.length - 1);
	update(expresstion);
}
function equal() {
	calculat();
}

//自定义加法函数，解决精度问题
function Add(arg1, arg2) {
	var r1, r2, m;
	try {
		r1 = arg1.toString().split('.')[1].length;
	} catch(e) {
		r1 = 0;
	}

	try {
		r2 = arg2.toString().split('.')[1].length;
	} catch(e) {
		r2 = 0;
	}

	m = Math.pow(10, Math.max(r1, r2));
	return (arg1 * m + arg2 * m) / m;
}

//自定义减法函数，解决精度问题
function Sub(arg1, arg2) {
	arg2 = arg2 * (-1);
	return Add(arg1,arg2);
}

//自定义乘法函数，解决精度问题
function multiply(arg1, arg2) {
	var m = 0, s1 = arg1.toString(), s2 = arg2.toString();
	try {
		m += s1.split(".")[1].length;
	} catch(e) {}

	try {
		m += s2.split(".")[1].length;
	} catch(e) {}
	return Number(s1.replace(".", "")) * Number(s2.replace(".", "")) / Math.pow(10, m);
}

//自定义除法函数，解决精度问题
function divide(arg1, arg2) {
	var t1 = 0, t2 = 0, r1,r2;
	try {
		t1 = arg1.toString().split(".")[1].length;
	} catch(e) {}
	try {
		t2 = arg2.toString().split(".")[1].length;
	} catch(e) {}

	with(Math) {
		r1 =Number(arg1.toString().replace(".", ""));
		r2 = Number(arg2.toString().replace(".", ""));
		return (r1 / r2) * pow(10, t2 - t1);
	}
}

//检查表达式是否符合规范并输出结果
function calculat() {
	//从文本框中读出表达式
	var expresstion = document.getElementById("input_field").value;
	var number = new Array();
	var operator = new Array();
	var dot = 0, temp = 0;
	var is_negative = false, illegal = true;

	//遍历表达式
	for (var i = 0; i < expresstion.length; i++) {
		var c = expresstion.charAt(i);
		var last = (i == 0) ? ' ' : expresstion.charAt(i - 1);
		var next = (i == expresstion.length - 1) ? '' : expresstion.charAt(i + 1);
		//若判断字符为数字
		if (c >= '0' && c <= '9') {
			if (dot == 0) {
				temp = temp * 10 + (c - '0');
			} else {
				temp = Add(temp, (c - '0') / Math.pow(10, dot));
				dot++;
			}
		}

		//若判断字符为小数点，需判断是否合法，即一个数中不能有多个小数点
		if (c == '.') {
			if (dot != 0) {
				alert("数字中不能出现多个小数点！");
				illegal = false;
				reset();
				break;
			} else {
				dot = 1;
			}
		}

		if (c == '+' || c == '-') {
			//判断是否为符合以及是否合法
			if (last == '(') {
				if (next != ')') {
					alert("正负号格式错误");
					illegal = false;
					reset();
					break;
				} else {
					is_negative = (c == '+') ? false : true;
					i++;
				}
				continue;
			}
			//此时+－号为操作符
			if (next == '×' || next =='÷' || next == '+' || next == '-') {
				alert("不能同时有多个运算符！");
				illegal = false;
				reset();
				break;
			} else {
				if (last >= '0' && last <= '9') {
					temp = (is_negative == true) ? (-1 * temp) : temp;
					number.push(temp);
					temp = 0;
					is_negative = false;
					dot = 0;
				}
				if (operator.length == 0)
				  operator.push(c);
				else {
					while (operator[operator.length - 1] == '+' || operator[operator.length - 1] == '-'
							|| operator[operator.length - 1] == '×' || operator[operator.length - 1] == '÷') {
						var t2 = number.pop();
						var t1 = number.pop();
						var op = operator.pop();
						if (op == '+') t1 = Add(t1, t2);
						if (op == '-') t1 = Sub(t1, t2);
						if (op == '×') t1 = multiply(t1, t2);
						if (op == '÷') {
							if (t2 == 0) {
								alert("除数不能为0");
								illegal = false;
								reset();
								break;
							} else {
								t1 = divide(t1, t2);
							}
						}

						number.push(t1);
						if (operator.length == 0) break;
					}
					operator.push(c);
				}
			}
		}

		if (c == '×' || c == '÷') {
			if (next == '+' || next == '-' || next == '×' || next == '÷') {
				alert("不能同时有多个运算符！");
				illegal = false;
				reset();
				break;
			} else {
				if (last >= '0' && last <= '9') {
					temp = (is_negative == true) ? (-1 * temp) : temp;
					number.push(temp);
					temp = 0;
					dot = 0;
					is_negative = false;
				}
				if (operator.length == 0) {
					operator.push(c);
				} else {
					while (operator[operator.length - 1] == '×'||operator[operator.length - 1] == '÷') {
						var t2 = number.pop();
						var t1 = number.pop();
						var op = operator.pop();
						if (op == '×') t1 = multiply(t1,t2);
						if (op == '÷') {
							if (t2 == 0) {
								alert("除数不能为0");
								illegal = false;
								reset();
								break;
							} else {
								t1 = divide(t1, t2);
							}
						}
						number.push(t1);
						if (operator.length == 0) break;
					}
					operator.push(c);
				}
			}
		}
		if (c == '(') {
			if ((last >= '0' && last <= '9')||(last == '.')) {
				alert("左括号前不能在数字或小数点！");
				reset();
				illegal = false;
				break;
			} else {
				if (next == '+' || next == '-') {
					continue;
				} else {
					operator.push('(');
				}
			}
		}

		if (c == ')') {
			if ((next >= '0' && next <= '9') || (next == '.')) {
				alert("右括号后面不能有小数点或数字！");
				illegal = false;
				reset();
				break;
			} else {
				if (last == '＋' || last == '-') {
					continue;
				} else {
					if (last >= '0' && last <= '9') {
						temp = (is_negative == true) ? (-1 * temp) : temp;
						number.push(temp);
						temp = 0;
						is_negative = false;
						dot = 0;
					}
					if (operator.length != 0)
					while (operator[operator.length - 1] != '(') {
						var t2 = number.pop();
						var t1 = number.pop();
						var op = operator.pop();
						if (op == '+') t1 = Add(t1, t2);
						if (op == '-') t1 = Sub(t1, t2);
						if (op == '×') t1 = multiply(t1, t2);
						if (op == '÷') {
							if (t2 == 0) {
								alert("除数不能为0");
								illegal = false;
								reset();
								break;
							} else {
								t1 = divide(t1, t2);
							}
						}
						number.push(t1);
						if (operator.length == 0) {
							alert("括号不匹配！");
							illegal = false;
							reset();
							break;
						}
					}
					operator.pop();
				}
			}
		}
	}
	if (illegal == true) {
		if (expresstion[expresstion.length - 1] >= '0' && expresstion[expresstion.length - 1] <= '9') {
			temp = (is_negative == true) ? (-1 * temp) : temp;
			number.push(temp);
		}

		while (operator.length != 0) {
			var op = operator.pop();
			if (number.length < 2 || op == '(') {
				alert("输入格式有错误！");
				reset();
				return;
			}
			var t2 = number.pop();
			var t1 = number.pop();
			if (op == '+') t1 = Add(t1, t2);
			if (op == '-') t1 = Sub(t1, t2);
			if (op == '×') t1 = multiply(t1, t2);
			if (op == '÷') {
							if (t2 == 0) {
								alert("除数不能为0");
								illegal = false;
								reset();
								break;
							} else {
								t1 = divide(t1,t2);
							}
						}
			number.push(t1);
			if (operator.length == 0) break;
		}

		if (number.length != 1) {
			alert("输入格式有错误！");
			reset();
		} else {
			var outPut = "" + number.pop();
			update(outPut);
		}
	}
}

