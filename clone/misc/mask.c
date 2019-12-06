// mask.c
// jwChen 2000.1.4

inherit ITEM;

void remove_mask(object me,int dead);
void create()
{
       set_name("���", ({ "mask" ,"mian ju" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("no_steal",1);
                set("long", "���ƺ���һ������Ƥ�Ƴɵ���ߡ�\n");
        }       setup();
}

void init()
{
        add_action("do_pretend", "pretend");
        add_action("do_put", "put");
        add_action("do_give", "give");
        add_action("do_drop", "drop");
}
int do_pretend(string arg)
{       
        object who,me,env;
        if (!arg)
                return notify_fail("�����װ˭��\n");

        me = this_player();
        env = environment(me);

        if (arg == "none" || arg == "cancel") 
        {
                if( !me->query_temp("apply/name") )
                        return notify_fail("�������Ͽ��˰��죬ʲôҲû��������\n");
                remove_mask(me,0);
                return 1;
        }
        if( (int)env->query("no_mask") )
                return notify_fail("�����ʲô��\n");
        if( !objectp(who = present(arg, environment(this_player()))) || !living(who) )
                return notify_fail("�����װ˭��\n");
        if( wizardp(who) )
                return notify_fail("������ɰ���\n");
        if((int)who->query("no_mask") )
                return notify_fail("���޷���װ"+who->name()+"\n");
        write("�㿪ʼ��װ" + who->name() + "��\n");

        if( me->query_temp("apply/name") )
                say(me->query("name")+"�����Ͽ���һ��Ƥ��������������ȥ��\n",me);
        else
                say(me->query("name")+"������һ�����Ƶ���Ƥ��ߡ�\n",me);
        me->set_temp("apply/name", ({who->name()}));
        me->delete_temp("apply/id");
        me->set_temp("apply/short", ({who->short()}));
        me->set_temp("apply/long", ({who->long()}));

        return 1;
}

void remove_mask(object me,int dead)
{
        me->delete_temp("apply/name");
        me->delete_temp("apply/id");
        me->delete_temp("apply/short");
        me->delete_temp("apply/long");
        if( !dead )
                message_vision("$N������ȡ����һ����Ƥ��ߡ�\n",me);
}
int do_put(string arg)
{
        string item,target;
        object  me;

        me = this_player();
        if( !arg ) 
                return 0;
        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return 0;
        if( item != "mask" && item != "mian ju" )
                return 0;
        if( me->query_temp("apply/name") )
                remove_mask(me,0);
        return 0;
}

int do_give(string arg)
{
        string item,target;
        object  me;

        me = this_player();
        if( !arg ) 
                return 0;
        if( sscanf(arg, "%s to %s", item, target)!=2 )
                return 0;
        if( item != "mask" && item != "mian ju" )
                return 0;
        if( me->query_temp("apply/name") )
                remove_mask(me,0);
        return 0;
}

int do_drop(string arg)
{
        object  me;

        me = this_player();
        if( !arg ) 
                return 0;
        if( arg != "mask" && arg != "mian ju" )
                return 0;
        if( me->query_temp("apply/name") )
                remove_mask(me,0);
        return 0;
}

void owner_is_killed()
{
        object me;

        me = this_player();
        if( me->query_temp("apply/name") )
                remove_mask(me,1);
}       
