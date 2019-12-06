// pour.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item, poison;
//        object obj, dest, *inv, obj2;
        object obj, dest;
//        int i, amount, poisontime;
        int poisontime;

	if(!arg) return notify_fail("��Ҫ��ʲô����\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("��Ҫ�������¶���\n");

	dest = present(target, me);
	if( !dest) return notify_fail("����û������������\n");

	if( !objectp(obj = present(item, me)) )
		return notify_fail("������û������������\n");
	if( !obj->query("pour_type"))
		return notify_fail("�ⲻ�Ƕ�ҩ����\n");

	if( dest->query("liquid/remaining") < 1 )
	{
		tell_object(me, "����һ��ȵĶ�û���ǲ����¶��ġ�\n");
		return 1;
	}
	message_vision( sprintf("$N��һ%s%s͵͵����%s��\n",
		obj->query("unit"), obj->name(), dest->name()), me );
	poisontime = (int)(me->query_skill("poison",1)/5);
	poison = obj->query("pour_type");
	dest->set("liquid/poison", poison);
	dest->set("liquid/poisontime", poisontime);
	destruct(obj);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : pour <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
�������кȵĶ�����
HELP
    );
    return 1;
}
