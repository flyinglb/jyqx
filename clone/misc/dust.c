// dust.c

inherit ITEM;
void setup()
{}
void create()
{
        set_name(HIC"��ʬ��"NOR, ({"dust"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���û�ʬ�𼣵Ļ�ʬ�ۣ�ֻҪһ����Ϳ��Ի�ȥ(dissolve)һ��ʬ�壡\n");
                set("value", 50);
        }
        setup();
}

void init()
{
   if( this_player()==environment() )
     add_action("do_dissolve", "dissolve");
}
                                                           
int do_dissolve(string arg)
{
   object ob;

   if( !arg ) return notify_fail("��Ҫ�û�ʬ���ܽ�ʲô������\n");
   if( !objectp(ob = present(arg, environment(this_player()))) )
     return notify_fail("����û������������\n");
   if( living(ob) || !ob->id("corpse") )
     return notify_fail("��ʬ��ֻ�������ܽ�ʬ�塣\n");
   message_vision(
     "$N��ָ������һ�㻯ʬ����$n�ϣ�ֻ����һ�����͡��������\n"
     "һ�ɿ��µĶ����$nֻʣ��һ̲��ˮ��\n", this_player(), ob);
   destruct(ob);
   return 1;
}

