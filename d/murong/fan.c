// nianyefan ��ҹ��


inherit ITEM;

void create()
{
        set_name("������ʮ����ҹ��,", ({"nianye fan", "fan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ʦ��ҹ�������������ҵ�����.��\n");
                set("unit", "ֻ");
                set("no_get", 1);
                set("no_give", 1);
           
        }
}
void init()
{
add_action("do_eat","eat");
}
int do_eat(string arg)
{object me;
me = this_player();
if (!arg || (arg!="nianye fan"&&arg!="fan")) return 0;
if( this_object()->query("gift_to_id") != me->query("id") ) 
        return notify_fail("�ⶫ����������İɣ�\n");
if(!me->query("marks/nianyefan_2001"))
{
message_vision("$N����������һ�ھͰ���ҹ�������˶������$N�Ǽ����ˡ�\n",me);
me -> add("combat_exp",20000);
me -> add("potential",2000);
tell_object(me,"�������ҹ������þ���ٱ���\n");
me->set("marks/nianyefan_2001",1);
}
else tell_object(me,"���Ѿ��Թ�һ����ҹ���ˣ�����ԣ�\n");
destruct(this_object());
return 1;
}

