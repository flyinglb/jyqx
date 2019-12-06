// remove.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_remove(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i;

	if( !arg ) return notify_fail("��Ҫ�ѵ�ʲô��\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			do_remove(me, inv[i]);
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");
	return do_remove(me, ob);
}

int do_remove(object me, object ob)
{
	string str;

	if( (string)ob->query("equipped")!="worn" )
		return notify_fail("�㲢û��װ������������\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unequip_msg")) )
			switch(ob->query("armor_type")) {
				case "cloth":
				case "armor":
				case "surcoat":
				case "boots":
					str = YEL "$N��$n����������\n" NOR;
					break;
				case "bandage":
					str = YEL "$N��$n���˿ڴ�����������\n" NOR;
					break;
				default:
					str = YEL "$Nж��$n��װ����\n" NOR;
			}
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : remove all | <��Ʒ����>
 
���ָ�������ѵ�����ĳ������.
 
HELP
    );
    return 1;
}
 
