// register.c
// Created by Xiang@XKX

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int register_user(string wizid, string name, string email)
{
	object ob, body;

       	if( objectp(body = find_player(name)) && geteuid(body)==name ) 
		return notify_fail("��ֻ�����������ʱ���ܸ����Ǽǡ�\n");

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if (!ob->restore())
		return 0;
	else {
		ob->set("registered", 1);
		ob->set("email", email);
		ob->set("registered_by", wizid);
		ob->save();
		destruct(ob);
		return 1; 
	}
}

int main(object me, string arg)
{
	string id, email;

	if (!arg || sscanf(arg, "%s %s", id, email) != 2) {
		return notify_fail("ָ���ʽ��register <id> <email>\n");
	}
	switch(register_user(me->query("id"), id, email)) {
	case 0: return notify_fail("�Ǽ�ʧ�ܡ�\n"); break;
	default: return notify_fail(id + " �Ѿ��ɹ��ر����Ǽ��ˡ�\n"); break;
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ��register <id> <email>

���ָ������������û�еǼǹ����û��Ǽ��õġ�
HELP
	);
	return 1;
}
