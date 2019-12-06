// config.c

#include <runtime_config.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 ) {
		write("Mud ���ƣ�\t\t" + get_config(__MUD_NAME__) + "\n"); 
		write("��·��ַ�����ŷ������ţ�" + get_config(__ADDR_SERVER_IP__) + "\n"); 
		write("Mudlib ·����\t\t" + get_config(__MUD_LIB_DIR__) + "\n"); 
		write("MudOS ִ�е�·����\t" + get_config(__BIN_DIR__) + "\n"); 
		return 1;
	}

	printf("get_config(%d) = %O\n", num, get_config(num));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : config

Show ���� MUD �� Startup Configuration ��
HELP
     );
     return 1;
}
