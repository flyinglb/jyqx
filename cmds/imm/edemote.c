// edemote.c

inherit F_CLEAN_UP;

int in_use;

int main(object me, string arg)
{
	mapping emote;

	if( !arg ) return notify_fail("��Ҫ�༭ʲô emote��\n");

	if( sscanf(arg, "-d %s", arg) ) {
		write("ɾ�� emote��" + arg + "\n");
		EMOTE_D->delete_emote(arg);
		return 1;
	}

	if( sscanf(arg, "-p %s", arg) ) {
		emote = EMOTE_D->query_emote(arg);
		printf("�ϴ��޸ģ�%s\n", emote["updated"]);
		printf("��������������������������\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
			emote["myself"], emote["others"], emote["myself_self"],
			emote["others_self"], emote["myself_target"], emote["target"],
			emote["others_target"] );
		return 1;
	}

	emote = EMOTE_D->query_emote(arg);
	emote = (["updated":geteuid(me)]);

	write("�༭ emote��" + arg + "\n");
	write("ѶϢ�����кü��У��� . ��ʾ������\n");
	write("ѶϢ�п�ʹ�õĲ��������¼��֣�\n");
	write("  $N  �Լ������֡�\n");
	write("  $n  ʹ�ö�������֡�\n");
	write("  $P  �Լ����˳ƴ����ʣ����㡢�㡢����������������\n");
	write("  $p  ʹ�ö�����˳ƴ����ʣ����㡢�㡢����������������\n");
	write("  $S  ���Լ��ĳƺ���\n");
	write("  $s  ���Լ��Ĵ�³�ƺ���\n");
	write("  $C  ���Լ����سơ�\n");
	write("  $c  �Ա��˵��سơ�\n");
	write("  $R  �Ա��˵���ơ�\n");
	write("  $r  �Ա��˵Ĵ�³�ƺ���\n");
	write("������������������������������������������������������������������������\n");
	write("��ָ������ʹ����� emote ʱ�����Լ�������ѶϢ��\n->");
	input_to("get_msg_myself", emote, arg);
	return 1;
}


int get_msg_myself(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself"]) ) emote["myself"] += "\n";
		write("��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��\n->");
		input_to("get_msg_others", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself"]) )
		emote["myself"] += msg + "\n";
	else emote["myself"] = msg;
	write("->");
	input_to("get_msg_myself", emote, pattern);
	return 1;
}

int get_msg_others(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others"]) ) emote["others"] += "\n";
		write("���Լ�ʹ����� emote ʱ���Լ�������ѶϢ��\n->");
		input_to("get_msg_myself_self", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["others"]) )
		emote["others"] += msg + "\n";
	else emote["others"] = msg;
	write("->");
	input_to("get_msg_others", emote, pattern);
	return 1;
}

int get_msg_myself_self(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself_self"]) ) emote["myself_self"] += "\n";
		write("���Լ�ʹ����� emote ʱ�������˿�����ѶϢ��\n->");
		input_to("get_msg_others_self", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself_self"]) )
		emote["myself_self"] += msg + "\n";
	else emote["myself_self"] = msg;
	write("->");
	input_to("get_msg_myself_self", emote, pattern);
	return 1;
}

int get_msg_others_self(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others_self"]) ) emote["others_self"] += "\n";
		write("�Ա���ʹ����� emote ʱ���Լ�������ѶϢ��\n->");
		input_to("get_msg_myself_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["others_self"]) )
		emote["others_self"] += msg + "\n";
	else emote["others_self"] = msg;
	write("->");
	input_to("get_msg_others_self", emote, pattern);
	return 1;
}

int get_msg_myself_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself_target"]) ) emote["myself_target"] += "\n";
		write("�Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ��\n->");
		input_to("get_msg_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself_target"]) )
		emote["myself_target"] += msg + "\n";
	else emote["myself_target"] = msg;
	write("->");
	input_to("get_msg_myself_target", emote, pattern);
	return 1;
}

int get_msg_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["target"]) ) emote["target"] += "\n";
		write("�Ա���ʹ����� emote ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ��\n->");
		input_to("get_msg_others_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["target"]) )
		emote["target"] += msg + "\n";
	else emote["target"] = msg;
	write("->");
	input_to("get_msg_target", emote, pattern);
	return 1;
}

int get_msg_others_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others_target"]) ) emote["others_target"] += "\n";
		EMOTE_D->set_emote(pattern, emote);
		write("Emote �༭������\n");
		return 1;
	}
	if( !undefinedp(emote["others_target"]) )
		emote["others_target"] += msg + "\n";
	else emote["others_target"] = msg;
	write("->");
	input_to("get_msg_others_target", emote, pattern);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : edemote [-d|-p] <emote>
 
���ָ������޸�, ɾ�� emote ���г�������. ���� -d ������ɾ��
ָ���� emote, -p ��������г�ָ�� emote ������. �г���˳�����
�� emote ʱ��ͬ.
 
���� emote ѶϢʱ��������Ŀ: û��Ŀ��, ָ��Ŀ����Ƕ��Լ�. ��
������ĳ��ѶϢ, ��ֱ���ڿհ������� '.' ����.
 
һ�� emote ѶϢ�����кܶ���, �ڿհ������� '.' ����������� emote.
 
�༭ emote ʱ���������µķ�������ʾ:
 
$N : �Լ�������.
$n : Ŀ�������.
$P : �Լ����˳ƴ�����.
$p : Ŀ����˳ƴ�����.
$S : ���Լ��ĳƺ���
$s : ���Լ��Ĵ�³�ƺ���
$C : ���Լ����سơ�
$c : �Ա��˵��سơ�
$R : �Ա��˵���ơ�
$r : �Ա��˵Ĵ�³�ƺ���
HELP
    );
    return 1;
}
