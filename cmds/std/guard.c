// guard.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":        "��",
	"south":        "��",
	"east":	        "��",
	"west":	        "��",
	"northup":      "����",
	"southup":      "�ϱ�",
	"eastup":       "����",
	"westup":       "����",
	"northdown":    "����",
	"southdown":    "�ϱ�",
	"eastdown":	"����",
	"westdown":	"����",
	"northeast":    "����",
	"northwest":    "����",
	"southeast":    "����",
	"southwest":    "����",
	"up":           "��",
	"down":	        "��",
	"out":	        "��",
	"in" :          "��",
	"enter" :       "����",
]);

int main(object me, string arg)
{
	string dir;
	object ob, *guards;
	mixed old_target;

	if( me->is_busy() )
		return notify_fail("������û�а취����ȥ�������£�\n");

	old_target = me->query_temp("guardfor");

	if( !arg || arg=="" ) {
		if( !old_target )
			return notify_fail("ָ���ʽ��guard <����> | <��Ʒ> | <����>\n");
		if( objectp(old_target) )
			if( living(old_target) )
				write("�������ػ���" + old_target->name() + "��\n");
			else
				write("��������" + old_target->name() + "һ�ԣ���ֹ�������ߡ�\n");
		else
			write("������ס " + old_target + " �ķ��򣬲�׼�κ����뿪��\n");
		return 1;
	}

	ob = present(arg, environment(me));

	if( ob ) {
		if( ob==me ) return notify_fail("�����Լ�������˵��Ҳ�������԰ɡ�\n");
		me->set_temp("guardfor", ob);
	}
	else if( environment(me)->query("exits/" + arg) ) {
		if( environment(me)->query("no_fight") )
			return notify_fail("���ﲻ׼ս������Ҳ��׼��ס����ȥ·��\n");
		me->set_temp("guardfor", arg);
		me->disable_command("skill");
	}
	else if( arg!= "cancel" )
		return notify_fail("��Ҫ����˭��ʲ�ᣬ�����ĸ�����\n");

	if( objectp(old_target) ) {
		guards = old_target->query_temp("guarded");
		guards -= ({ me });
		old_target->set_temp("guarded", guards);
		if( living(old_target) )
			tell_object( old_target, me->name() + "���ٱ������ˡ�\n");
	} else if( stringp(dir = me->query_temp("pending/guarding")) ) {
		guards = environment(me)->query("guarded/" + dir);
		if( arrayp(guards) ) {
			guards -= ({ me });
			environment(me)->set("guarded/" + dir, guards);
		}
		me->enable_path();
	}
	me->delete_temp("guardfor");

	if( arg=="cancel" ) {
		write("ʲôҲ�������ˣ����Ǻ����ɡ�\n");
		return 1;
	}

	if( objectp(ob) ) {
		ob->add_temp("guarded", ({ me }) );
		if( living(ob) )
			message_vision("$N��ʼ����$n��\n", me, ob);
		else
			message_vision("$Nվ�����ϵ�$nһ���������������ȡ�ߡ�\n", me, ob);
	} else {
		me->set_temp("pending/guarding", arg);
		environment(me)->add("guarded/" + arg, ({ me }));
		message_vision("$N��ʼ��ס��" + default_dirs[arg] + "�ķ������κ���ͨ�С�\n", me);
	}

	return 1;
}

// guard             �����κβ�������ʾ��Ŀǰ guard �Ķ���
int help(object me)
{
	write(@TEXT
ָ���ʽ��guard [<ĳ��>|<����ĳ��>|<ĳ������>|cancel]

���ָ�����������÷�ʽ���ֱ����᣺

guard <ĳ��>      ����<ĳ��>�����������ܵ�����ʱ�������߻��Զ�����ս��������
                  �ܹ�����˳λ�����ڱ�������ǰ�棬���ֻ�й���˳λǰ�ĸ�Ŀ��
                  �Ż��ܵ����������������������ĸ���  guard �㣬��Ͳ�����
                  ���κι�����

guard <����ĳ��>  ��ס���ڵ��ϵ�ĳ����������ֹ�������ã�ֻҪ�㻹��������䣬
                  ����û��æ�������£����˾��޷�������������������뿪���ٻ�
                  ����ֻҪ�������ڣ����Խ������ػ�֮�¡�

guard <ĳ������>  ��סĳ�����ڷ�ֹ�����˴���������뿪���������������������
                  �ĵ��˻���·��������¡�
                  Ŀǰ�ݲ������س���������ܡ�

guard cancel      ȡ����ǰ�� guard ����

ע�⣬ͨ������ guard <ĳ��> ���������⣬ֻҪ��һ�ƶ���guard ��״̬�ͻ�����
TEXT
	);
	return 1;
}
