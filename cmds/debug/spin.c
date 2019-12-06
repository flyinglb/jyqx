//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i;
	object *inv, ob;

	if( arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	inv = all_inventory(ob);
	if( !sizeof(inv) ) {
		write((ob==me)? "Ŀǰ������û���κζ�����\n"
			: ob->name() + "����û��Я���κζ�����\n");
		return 1;
	}
	printf("%s���ϴ���������Щ����(���� %d%%)��\n%s\n",
		(ob==me)? "��": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
		implode(map_array(inv, "inventory_desc", this_object()), "\n") );

	return 1;
}

string inventory_desc(object ob)
{
	return sprintf("%s%s",
		ob->query("equipped")? HIC "��" NOR:"  ",
		ob->short()
	);
}

int help (object me)
{
        write(@HELP
ָ���ʽ: inventory
 
���г���(��)Ŀǰ������Я����������Ʒ��
 
ע : ��ָ����� " i " ���档
 
HELP
);
        return 1;
}
