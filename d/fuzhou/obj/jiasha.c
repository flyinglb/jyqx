// jiasha.c
//Jay 4/8/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_move", "move");
}

void create()
{
        set_name("����", ({"jia sha", "jia", "sha"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ɵ��Ѿ���������ɫ�����ģ������кö������\n");
                set("unit", "��");
                set("material", "cloth");
                set("no_get", "�������������뿪�Ƕ���\n");

        }
        setup();
}

int do_move(string arg)
{
        object book;
        object me = this_player();
        if (!id(arg))
                return 0;
        if (this_player()->query("passwd") ) {
                if (!present("kuihua baodian",me)){
                message_vision(
"$N�����Ų�����ģ�����һЩ����...��ͻȻ�����ĵĿ����й���һ���鵽$N���С�\n", this_player());
                book = new(__DIR__"kuihua");
                book->move(me);
                return 1;
                }
                message_vision(
"$N�����Ų�����ģ�����һЩ������Ǻ��$Nֱ�����硣\n", this_player());
                return 1;
        }
        else {
                message_vision(
"$N�����Ų�����ģ�ͻȻ�����ĵĿ�����ð��һ�ɶ��������$N�ı����С�\n", this_player());
                me->die();
                return 1;
        }
}

