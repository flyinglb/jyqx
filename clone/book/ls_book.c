//���¾Ž�����(Lonely_sword_book)
// ls_book.c
// Date: Oct.6 1997 by That

inherit ITEM;
inherit F_AUTOLOAD;
int do_study(string);
int study(object me, string arg)
{
    object ob;
    int myskill, cost;

    cost=20;                                            //ÿ��һ�κ�20��
    myskill=me->query_skill("lonely-sword", 1);
    if (!arg || !objectp(ob = present(arg, me)))
        return notify_fail("��Ҫ��ʲô��\n");
    if (!me->query_skill("literate", 1)||me->query_skill("literate",1) < 100)
        return notify_fail("���ս��ף���ʲô����������\n");
    if (me->is_busy())
        return notify_fail("��������æ���ء�\n");
    if (me->is_fighting() )
        return notify_fail("���޷���ս����ר�������ж���֪��\n");
    if ((int)me->query("combat_exp") < 50000)
        return notify_fail("���ʵս���鲻�㣬����ѧ���¾Ž���\n");
    if (myskill>299)
        return notify_fail("���ж���һ���������������˵�Ķ�����Զ�̫ǳ�ˡ�\n");
    if (myskill<75)
        return notify_fail("�����һ����,����ȴ�����ջ�\n");
    if ((int)me->query("jing")>cost )
    {
       if (myskill*myskill*myskill/10>(int)me->query("combat_exp") )
       {
          printf("Ҳ����ȱ��ʵս���飬��Զ��¾Ž���������˵�Ķ��������޷���ᡣ\n");
       }
       else
       {
          printf("���ж��йض��¾Ž������ϵļ��ɣ��ƺ��е��ĵá�\n");
          me->improve_skill("lonely-sword", (int)me->query_skill("literate", 1)+(int)me->query("int"));
       }
    }
    else
    {
       cost=me->query("jing");
       write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
    }
    me->receive_damage("jing", cost );
    return 1;
}
void create()
{
        set_name(HIG"���¾Ž�����"NOR, ({ "lonely_sword_book","ls_book" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("no_drop","���ǵ����±���������ܶ�ʧ��\n");
                set("no_put","���ǵ����±���������ܶ�ʧ��\n");
                set("no_get",1);
                set("no_steal",1);
                set("long","���¾Ž���������ֻ����ϰ(yanxi)��\n");
                set("value", 1000);
                set("material", "paper");
                set("master_id","npc");
        }
}

void init()
{
        add_action("do_study","yanxi");
}

int do_study(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object();

        write("�ۣ�����ǧ�Ŷ����Ľ�����\n");
        study(me,arg);
        return 1;
}

string query_autoload()
{
        object me;
        me = this_object();
        return me->query("master_id");
}
void autoload(string arg)
{
        set("master_id",arg);
}
void owner_is_killed()
{
        write(HIY"ֻ����ǰ���һ��...������.....\n"NOR);
        destruct(this_object());
}
