// ban.c
// Created by Xiang@XKX

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
                BAN_D->print_banned_sites();
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("���ܽ��� *, +, ? ��β�ĵ�ַ��\n");
		else
                        BAN_D->add_banned_site(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
                BAN_D->del_banned_site(site);
	else write("ָ���ʽ��ban [+|- site]\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
ָ���ʽ��ban [+|- site]

����������������ֹ�������⵷�ҡ�
HELP
	);
	return 1;
}
