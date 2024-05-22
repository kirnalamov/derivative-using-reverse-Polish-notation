#include "pri.h"
#include "pri.h"

#include <Windows.h>

#include <vector>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace Project6;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew pri);
	return 0;
}


std::vector<std::string> priv_vir;
int mast = 100;
std::set<std::string> tokens;

std::set<std::string> tokens_rith{
	"^","sin","cos","tg","ctg","_"
};
std::set<std::string> unar{
	"_","sin","cos","tg","ctg"
};


double unar_action(std::string& token, double x) {
	if (token == "sin")return std::sin(x);
	if (token == "cos")return std::cos(x);
	if (token == "tg") {
		if (abs(std::cos(x) - 0) > 1e-2)
			return std::tan(x);
		else return -1e18;
	}

	if (token == "ctg") {
		if (abs(std::sin(x)- 0) > 1e-2)
			return 1 / std::tan(x);
		else return -1e18;
	}
	if (token == "_")return x * -1;
}
double action(std::string& token, double a, double b) {
	if (token == "+")return a + b;
	if (token == "-")return a - b;
	if (token == "/") {
		if (abs(b - 0) > 1e-2) return a / b;
		return -1e18;
	}
		
	if (token == "*")return a * b;
	if (token == "%")return (int)a % (int)b;
	if (token == "^")return std::pow(a, b);

}
double unar_action_p(std::string& token, double x,double y) {
	if (token == "sin")return std::cos(y) * x;
	if (token == "cos")return -std::sin(y) * x;
	if (token == "tg")return 1 / pow(std::cos(y), 2) * x ;
	if (token == "ctg")return -1 / pow(std::sin(y), 2) * x;
	if (token == "_")return x * -1 ;
}

double action_p(std::string& token, double a, double b, bool a_1, bool b_1, double cur_a, double cur_b) {
	if (token == "+") {
		double a_2 = 0;
		if (a_1) a_2 = a;
		double b_2 = 0;
		if (b_1) b_2 = b;
		return a_2 + b_2;
	}
	if (token == "-") {
		double a_2 = 0;
		if (a_1) a_2 = a;
		double b_2 = 0;
		if (b_1) b_2 = b;
		return a_2 - b_2;
	};
	if (token == "/") {
		double a_2 = 0;
		if (a_1) a_2 = a;
		double b_2 = 0;
		if (b_1) b_2 = b;
		return (a_2 * cur_b - cur_a * b_2) / (cur_b * cur_b); //  (a'b - ab') / b^2
	};
	if (token == "*") {
		double a_2 = 0;
		if (a_1) a_2 = a;
		double b_2 = 0;
		if (b_1) b_2 = b;
		return (a_2 * cur_b + cur_a * b_2);
	};
	if (token == "%")return 0;
	if (token == "^") {
		if (a_1 && !b_1 )return cur_b * pow(cur_a, cur_b - 1) * a;

		else if (a_1 && b_1) return pow(std::exp(1),cur_b * std::log(cur_a)) * (b * std::log(cur_a) + cur_b / cur_a * a) ;
		else return pow(cur_a, cur_b) * std::log(cur_a) * b;

	};

}

std::string unar_action_p_strin(std::string& token,double x_1, double y_1,  std::string x, std::string y) {
	if (token == "sin" || std::cos(y_1) == 0) {
		if (x_1 == 0) {
			return "";
		}
		if (x_1 == 1) return "(cos" + y + ")";
		return "(cos" + y + "*" + x +")";
	};
	if (token == "cos") {
		if (x_1 == 0 || std::sin(y_1) == 0) {
			return "";
		}
		
		if (x_1 == 1) return "(-sin"+ y + ")";
		return "(-sin" + y + "*" + x + ")";
	};
	if (token == "tg"){
		if (x_1 == 0) return "";

		if (x_1 == 1) return "(1/(cos" + y + "^2" + "))";
		return  "(1/(cos" + y + "^2)*" + x + ")";
	}
	if (token == "ctg") {
		if (x_1 == 0) return "";

		if (x_1 == 1) return "(cos" + y + ")";
		return  "(-1/(sin" + y + "^2)*" + x + ")";
	};
	if (token == "_") {
		if (x_1 == 0) return ""; 
		if (x_1 == 1|| x == "x") return "-1";
		return  "(-"  + x + ")";
	};
}

std::string action_p_strin(std::string& token, double a, double b, bool a_1, bool b_1, double cur_a, double cur_b, std::string a_s, std::string b_s, std::string cur_a_s, std::string cur_b_s ) {
	if (token == "+") {
		double a_2 = 0;
		if (a_1) a_2 = a;
		double b_2 = 0;
		if (b_1) b_2 = b;
		if (a_2 == 0 && b_2 == 0) return "0";
		if (a_2 == 0 && b_2 != 0) return b_s; 
		if (a_2 != 0 && b_2 == 0) return a_s;
		return "(" + a_s + "+"+  b_s +  ")";
	}
	if (token == "-") {
		double a_2 = 0;
		if (a_1) a_2 = a;
		double b_2 = 0;
		if (b_1) b_2 = b; 
		if(a_2 == 0 && b_2 == 0) return "0";
		if (a_2 == 0 && b_2 != 0) return b_s;
		if (a_2 != 0 && b_2 == 0) return a_s;
		return "(" + a_s + "-" + b_s + ")";
		
	};
	if (token == "/") {
		double a_2 = 0;
		if (a_1) a_2 = a;
		double b_2 = 0;
		if (b_1) b_2 = b;
		if (a_2 == 0 || cur_b == 0) return   "((-" + cur_a_s + "*" + b_s + ")" + " / " + cur_b_s+ "^2" + ")";
		if (b_2 == 0 || cur_a == 0) return   "(("+ a_s + "*" + cur_b_s + ")" + " / " + cur_b_s+ "^2" + ")";
		return   "(("+ a_s + "*" + cur_b_s + "- " + cur_a_s + "*" + b_s +  ")" + " / " + cur_b_s+ "^2" + ")";
		

	};
	if (token == "*") {
		double a_2 = 0;
		if (a_1) a_2 = a;
		double b_2 = 0;
		if (b_1) b_2 = b;
		if (a_2 == 0 && b_2 == 0) return "0";
		if (a_2 == 0 || cur_b == 0) return   "(" + cur_a_s + "*" + b_s + ")" ;
		if (b_2 == 0 || cur_a == 0) return   "(" + a_s +  "*" + cur_b_s + ")";
		return "(" + cur_a_s + "*" + b_s +"+" + a_s + "*" + cur_b_s + ")";
	};
	if (token == "%")return "";
	if (token == "^") {
		if (a_1 && !b_1) {
			if (cur_b != 0 || a != 0) {
				return "(" + cur_b_s + "*" + a_s + "*" + cur_a_s + "^(" + cur_b_s + "-1)";
			}
			
			
			return "0";
		}

		else if (a_1 && b_1) {
			if (pow(std::exp(1), cur_b * std::log(cur_a)) == 0 || (b == 0 && a == 0)) {
				return "";
			}
			if (b_1 == 0) {
				return "e^(" + cur_b_s + "*ln" + cur_a_s + ")*(" + cur_b_s + "/" + cur_a_s + "*" + a_s + ")";
			}
			if (a_1 == 0) {
				return "e^(" + cur_b_s + "*ln" + cur_a_s + ")*(" + b_s + "*ln" + cur_a_s + ")";
			}

			return "e^(" + cur_b_s + "*ln" + cur_a_s + ")*(" + b_s + "*ln" + cur_a_s + "+" + cur_b_s + "/" + cur_a_s + "*" + a_s + ")";
		}
		else {
			if (b == 0) return "0";
			return cur_a_s + "^" + cur_b_s + "*ln" + cur_a_s + "*" + b_s;
		}

	};

}

std::string unar_action_strin(std::string& token, double x, std::string e) {
	if (token == "sin")return "(sin"  + e + ")";
	if (token == "cos")return "(cos" +e + ")";
	if (token == "tg") {
		if (abs(std::cos(x) - 0) > 1e-2)
			return "(tg" + e+ ")";
		else return "";
	}

	if (token == "ctg") {
		if (abs(std::sin(x) - 0) > 1e-2)
			return "(1/(tg" + e + "))";
		else return "";
	}
	if (token == "_")return "(-" + e + ")";
}
std::string action_strin(std::string& token, double a, double b, std::string a_s, std::string b_s) {
	if (token == "+") {
		
		if (a == 0 && b != 0) return b_s;
		if (a != 0 && b == 0) return a_s;
		return "(" + a_s + "+" + b_s + ")";
	}
	if (token == "-") {
		
		if (a == 0 && b != 0) return "(-"+b_s+ ")";
		if (a != 0 && b == 0) return a_s;
		return "(" + a_s + "-" + b_s + ")";

	};
	if (token == "/") {
		if (b == 0) return "0";
		if (b == 1) return a_s;
		return   "(" + a_s + "/" + b_s + ")";


	};
	if (token == "*") {
		if (a == 0 || b == 0) return  "0";
		return "(" + a_s + "*" + b_s + ")";
		
	};
	if (token == "%")return "0";
	if (token == "^") {
		return "(" + a_s + "^" + b_s +")";

	};

}

bool isDitgit(char n) {
	return ('0' <= n) && ('9' >= n) || ('.' == n);
}


double get_int(std::string& s) {
	double tmp = 0;
	int k = 0;
	bool f = false;
	int r = 1;
	for (auto i : s) {
		if (i != '.' && i != '-') {
			tmp *= 10;
			tmp += i - '0';
			if (f)k++;
		}
		else {
			if (i == '.')f = true;
			else r = -1;
		}
	}
	return tmp / (std::pow(10, k)) * r;
}


std::map<std::string, int> priority{
	{ "_", 2 },
	{ "^", 2 },
	{ "sin", 3 },
	{ "cos", 3 },
	{ "ctg", 3 },
	{ "tg", 3 },
	{ "*", 1 },
	{ "/", 1 },
	{ "%", 1 },
	{ "+", 0 },
	{ "-", 0 },
	{ "(", -2 },
	{ ")", -1 },
};

std::vector<std::string> get_raz_tokens(std::string& s) {
	std::string tmp = "";
	std::vector<std::string> arr;
	bool flag = true;
	for (auto i : s) {
		if (flag && isDitgit(i)) {
			tmp += i;
		}
		else if (flag && !isDitgit(i)) {
			if (tmp != "") {
				arr.push_back(tmp);
				arr.push_back("*");
			}
			tmp = i;
			flag = false;
		}
		else if (!flag && !isDitgit(i)) {
			tmp += i;
		}
		else {
			if (tmp != "") {
				arr.push_back(tmp);
				arr.push_back("*");
			}
			tmp = i;
			flag = true;
		}

	}
	if (tmp != "") {
		arr.push_back(tmp);
	}
	if (arr.size() > 0 && arr.back() == "*") arr.pop_back();
	return arr;
}

void tokens_str(std::vector<std::string>& tmp, std::string line) {
	line += ' ';
	std::string current_operand = "";
	for (int i = 0; i < line.size(); i++) {
		for (auto& op : tokens)
		{
			if (current_operand.find(op) != std::string::npos) {
				int n = op.size();
				while (n--)
				{
					current_operand.pop_back();

				}
				if (current_operand != "") {
					if (!tmp.empty() && (!(tokens.find(tmp.back()) != tokens.end()) ||
						tmp.back() == ")")) tmp.push_back("*");
					for (auto& cur : get_raz_tokens(current_operand))tmp.push_back(cur);
				};
				if (!tmp.empty() && op == "(" && !(tokens.find(tmp.back()) != tokens.end())) tmp.push_back("*");
				if (op == "-" && (tmp.empty() || tokens.find(tmp.back()) != tokens.end())) tmp.push_back("_");
				else tmp.push_back(op);


				current_operand = "";
				break;

			}
		}
		if (line[i] != ' ') current_operand += line[i];
	}
	if (current_operand != "") {
		for (auto& cur : get_raz_tokens(current_operand))tmp.push_back(cur);
	};


}



std::vector<std::string> get_stak(std::string& line) {

	std::vector<std::string> tokens_line;
	tokens_str(tokens_line, line);
	std::vector<std::string> ans_arr;
	std::vector<std::string > stak;
	for (auto& token : tokens_line) {
		if (tokens.find(token) != tokens.end()) {

			if (token != ")") {
				if (tokens_rith.find(token) != tokens_rith.end()) {
					while (!stak.empty() && priority[stak.back()] > priority[token] && token != "(")
					{
						ans_arr.push_back(stak.back());
						stak.pop_back();
					}
				}
				else {
					while (!stak.empty() && priority[stak.back()] >= priority[token] && token != "(")
					{
						ans_arr.push_back(stak.back());
						stak.pop_back();
					}
				}
				stak.push_back(token);
			}
			else
			{
				while (!stak.empty() && stak.back() != "(")
				{
					ans_arr.push_back(stak.back());
					stak.pop_back();
				}
				stak.pop_back();
			}

		}
		else {
			ans_arr.push_back(token);
		}
	}
	while (!stak.empty())
	{
		ans_arr.push_back(stak.back());
		stak.pop_back();
	}


	return ans_arr;
}

double get_ans(std::vector<std::string>& tmp, std::map<std::string, std::string>& per) {
	std::vector<double> stack;
		for (auto& i : tmp)
	{
		if (!(tokens.find(i) != tokens.end())) {
			if (isDitgit(i[0])) stack.push_back(get_int(i));
			else stack.push_back(get_int(per[i]));
		}
		else {
			if (unar.find(i) != unar.end()) {
				double tmp = unar_action(i, stack.back());
				if (tmp == -1e18) return tmp;
				stack.pop_back();
				stack.push_back(tmp);
			}
			else {
				double a = stack.back();
				stack.pop_back();
				double tmp = action(i, stack.back(), a);
				if (tmp == -1e18) return tmp;
				stack.pop_back();
				stack.push_back(tmp);
			}
		}
	}
	return stack[0];

}
std::pair<double,std::string> get_proiz(std::vector<std::string>& tmp, std::map<std::string, std::string>& per) {
	std::vector<double> stack;
	std::vector<double> stackp;
	std::vector<bool> stackp2;
	std::vector<std::string> pr;
	std::vector<std::string> pr2;
	for (auto& i : tmp)
	{
		if (!(tokens.find(i) != tokens.end())) {
			if (isDitgit(i[0])) stack.push_back(get_int(i));
			else stack.push_back(get_int(per[i]));
			if (isDitgit(i[0])) {
				stackp.push_back(get_int(i));
				stackp2.push_back(0);
				pr.push_back(i);
			}
			else {
				pr.push_back("1");
				stackp.push_back(1);
				stackp2.push_back(true);
			}
		
			pr2.push_back(i);
		}
		else {
			if (unar.find(i) != unar.end()) {
				double a = stack.back();
				double tmp = unar_action(i, a);
				std::string tmp2 = unar_action_strin(i, a, pr2.back());
				std::string a_2 = pr2.back();
				
				stack.pop_back();
				pr2.pop_back();
				stack.push_back(tmp);
				pr2.push_back(tmp2);


				tmp = 0;
				std::string po= "";
				if (stackp2.back()) {
					tmp = unar_action_p(i, stackp.back(),a);
					po = unar_action_p_strin(i, stackp.back(),a ,pr.back(),a_2) ;
				}
				bool r = stackp2.back();
				stackp.pop_back();
				pr.pop_back();
				pr.push_back(po);
				stackp2.pop_back();
				stackp.push_back(tmp);
				stackp2.push_back(r);

			}
			else {
				double a = stack.back();
				stack.pop_back();
				double b = stack.back();
				std::string a_1 = pr2.back();
				pr2.pop_back();
				std::string  b_1 = pr2.back();
				double tmp = action(i, b, a);
				std::string tmp2 = action_strin(i, b, a,a_1,b_1);
				stack.pop_back();
				stack.push_back(tmp);
				pr2.pop_back();
				pr2.push_back(tmp2);

				std::string c_s = pr.back(); 
				 
				pr.pop_back(); 
				std::string d_s = pr.back(); 
				pr.pop_back();
				double c = stackp.back();
				bool c_1 = stackp2.back();
				stackp.pop_back();
				stackp2.pop_back();
				double d = stackp.back();
				bool d_1 = stackp2.back();
				tmp = action_p(i, d, c, d_1, c_1, b, a);
				tmp2 = action_p_strin(i , d,c,d_1,c_1, b,a,d_s,c_s, b_1,a_1);
				pr.push_back(tmp2);
				stackp.pop_back();
				stackp2.pop_back();
				stackp.push_back(tmp);
				stackp2.push_back(c_1 || d_1);

			}
		}

	}
	return { stackp[0],pr[0] };

}

static std::string toStandardString(System::String^ string)
{
	using System::Runtime::InteropServices::Marshal;

	if (string->Length == 0 || string->Length < 0)
	{
		MessageBox::Show("No field can be empty");

	}

	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);


	return returnString;
}

System::Void Project6::pri::paint() {
	auto a1 = board->CreateGraphics();
	a1->Clear(Color::White);

	Pen^ pen = gcnew Pen(Color::Red, 2);
	Pen^ pen1 = gcnew Pen(Color::Black, 2);
	Pen^ pen2 = gcnew Pen(Color::LightGray, 1);



	for (int i = 709 / 2, cou = 0; i >= 0; i -= mast, cou--) {

		a1->DrawLine(pen2, i, 0, i, 534);
		a1->DrawString(cou.ToString(), this->Font, Brushes::Black, i, 534 / 2);
	}
	for (int i = 709 / 2, cou = 0; i <= 709; i += mast, cou++) {
		a1->DrawLine(pen2, i, 0, i, 534);
		a1->DrawString(cou.ToString(), this->Font, Brushes::Black, i, 534 / 2);
	}
	for (int i = 534 / 2, cou = 0; i >= 0; i -= mast, cou++) {
		a1->DrawLine(pen2, 0, i, 709, i);
		a1->DrawString(cou.ToString(), this->Font, Brushes::Black, 709 / 2, i);
	}
	for (int i = 534 / 2, cou = 0; i <= 709; i += mast, cou--) {
		a1->DrawLine(pen2, 0, i, 709, i);
		a1->DrawString(cou.ToString(), this->Font, Brushes::Black, 709 / 2, i);
	}
	a1->DrawLine(pen1, 709 / 2, 0, 709 / 2, 534);
	a1->DrawLine(pen1, 0, 534 / 2, 709, 534 / 2);

	int last_x = -1e18;
	int last_y = -1e18;
	bool f = false;
	for (double x = 709 / 2 * -1 - 1; x <= 709 / 2; x += 1/(50.0/mast) ){
		double x_1 = (x) / mast;
		std::map<std::string, std::string> zn;
		zn["x"] = std::to_string(x_1);
		zn["X"] = std::to_string(x_1);
		double a = get_ans(priv_vir, zn);

		
		int x1 =last_x;
		int y = last_y;
		if (a != -1e18 && !isnan(a)) {
			x1 = 709 / 2 + x;
			y = 534 / 2 - a * mast;
		}
		if (f && a != -1e18 && !isnan(a) && y <1e3 && y > -1e3) {
			a1->DrawLine(pen, last_x, last_y, x1, y);

		}
		f = true;
		if (a == -1e18 || isnan(a)) {
			f = false;

		}
	
		last_x = x1;
		last_y = y;
	}

}



System::Void Project6::pri::get_expression_Click(System::Object^ sender, System::EventArgs^ e)
	
{	using namespace System::Collections::Generic;
	for (auto& i : priority)
	{
		tokens.insert(i.first);
	}
	String^ s = gcnew String(expression->Text);
	std::string line = toStandardString(s);

	int h = 534, w = 709;

	if (line != "") {
		
		std::string tmp="";
		priv_vir = get_stak(line);

		for (auto& i : priv_vir)
		{
			tmp += i + ' ';
		}
		String^ newSystemString = gcnew String(tmp.c_str());
		posk_text->Text =newSystemString;
		
		paint();
		

	}
	return System::Void();
}



System::Void Project6::pri::trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	if (abs(mast - trackBar1->Value) > 1) {
		mast = trackBar1->Value;
		paint();
	}
}

System::Void Project6::pri::p()
{
	using namespace System::Collections::Generic;
	for (auto& i : priority)
	{
		tokens.insert(i.first);
	}
	String^ s = gcnew String(expression->Text);
	std::string line = toStandardString(s);

	int h = 534, w = 709;

	if (line != "") {

		std::string tmp = "";
		priv_vir = get_stak(line);

		for (auto& i : priv_vir)
		{
			tmp += i + ' ';
		}
		String^ newSystemString = gcnew String(tmp.c_str());
		posk_text->Text = newSystemString;

		paint();


	}
	return System::Void();
}

System::Void Project6::pri::board_Click(System::Object^ sender, System::EventArgs^ e)
{
	double x1 = Cursor->Position.X - this->Location.X- board->Location.X;
	double y1 = Cursor->Position.Y - board->Location.Y;

	paint();
	std::map<std::string, std::string> zn;
	double z = 709 / 2;
	double x_1 = (x1-z) / mast  ;
	zn["X"] = std::to_string(x_1);
	zn["x"] = std::to_string(x_1);

	double a = get_ans(priv_vir, zn);
	if (a != -1e18 && !isnan(a)) {
		
		auto tmp = get_proiz(priv_vir, zn);
		double k = tmp.first;
		auto a1 = board->CreateGraphics();
		String^ newSystemString = gcnew String(tmp.second.c_str());
		output_p->Text = newSystemString;
		double x_1_1 = -709 / 2- z;
		double y_1_1 = (k * (x_1_1/mast -x_1) +a);
		double x_1_2 = 709 / 2 ;
		double y_1_2 =k * (x_1_2/mast -x_1) + a ;
		int aa = 709 / 2 + x_1_1;
		int aaa = 534 / 2 - y_1_1 * mast;
		int bb = 709 / 2 + x_1_2;
		int bbb = 534 / 2 - y_1_2 * mast;
		Pen^ pen = gcnew Pen(Color::Blue, 2);
		a1->DrawLine(pen, aa, aaa, bb, bbb);
	}
	
	


}
