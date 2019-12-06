// xisuijing.c ϴ�辭

inherit ITEM;
int do_study(string);
string* skill = ({
	"whip",
	"finger",
	"hand",
	"cuff",
	"claw",
	"strike",
});
void create()
{
        set_name(YEL"ϴ�辭"NOR, ({ "xisuijing" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long","�Ȿ��ֽͲ�������������ѧ�伮���Ǵ�Ħ������ھ������׽һ��
��������ľ����伮��\n");
                set("value", 10);
                set("material", "paper");
        }
}

void init()
{
	add_action("do_study","canwu");
}

int do_study(string arg)
{
	object where;
	object ob = this_object();
	object me = this_player();
	int myskill, cost, i, exp;

	cost=50;
	where = environment(me);
	if (!arg || !objectp(ob = present(arg, me)))
		return notify_fail("��Ҫ����ʲô��\n");
	if ((string)where->query("short")!="��ĦԺ��¥")
		return notify_fail("ϴ�辭ֻ���ڴ�ĦԺ�����\n");
	if (!me->query_skill("literate",1)||me->query_skill("literate",1)<100)
	{
		write("���ֽͲ������ȥ������ʲô����������\n");
		return 1;
	}
//	if (!me->query_skill("yijinjing",1)||me->query_skill("yijinjing",1)<100)
//	{
//		write("Ҳ����û���ڻ��ͨ�׽���������ϴ�辭Ī�����\n");
//		return 1;
//	}
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if (me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");
	exp = (int)me->query("combat_exp");
	if (exp < 300000)
	{
		write("���ʵս���鲻�㣬���ܲ���ϴ�辭��\n");
		return 1;
	}
	if ((int)me->query("jing")>cost)
	{
		for ( i=sizeof(skill); i>0; i-- )
		{
			myskill=me->query_skill(skill[i-1], 1);
			if ( myskill<180 && myskill>1 && myskill*myskill*myskill/10<exp)
			{
me->improve_skill(skill[i-1],(int)(me->query_skill("literate",1)+me->query("int"))/2);
			}
		}
		printf("�����ϴ�辭�ϵľ��ģ��ƺ��е��ĵá�\n");
		me->receive_damage("jing", cost );
	}
	else
	{
		cost=me->query("jing");
		write("�����ڹ���ƣ�룬�޷�ר����������ϴ�辭��\n");
	}
	return 1;
}
