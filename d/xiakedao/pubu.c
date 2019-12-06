// pubu.c �ٲ�

inherit ROOM;

#include <ansi.h>

int do_jump(string arg);
int do_plump(string arg);
void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
��������ˮ�����������¡¡�����糱ˮ����һ�㣬̧ͷһ����
ֻ��һ�����ٲ�(pubu)���������ӵ������Ӹ�����ֱк������������
������(xuanya)��������������������ͷ!!!
LONG  );
        set("exits", ([ /* sizeof() == 3 */
                "northdown" : __DIR__"road4",
        ]));
        set("outdoors", "xiakedao");
        set("item_desc",([
            "pubu"   : "����ϸһ�����ٲ���������г��ڣ����ƺ�������(jump)��ȥ��\n",
            "xuanya" : "��������������ʲôҲ����������ɲ�Ҫ��(plump)��ȥѽ��\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump","jump");
        add_action("do_plump","plump");
}
int do_jump(string arg)
{
        int n;
        n = this_player()->query_skill("dodge",1);
        if( !arg || arg!= "pubu" )
          {
          write("��Ҫ����������!\n");
          return 1;
        }
message_vision("$N���ٲ�ǰվ�������һ������ͻȻԾ��\n", this_player());
        if(n >=80)
        {
message_vision("ֻ��$N�ż�һ��أ�������ƮƮ��Ծ���ٲ�֮�С�\n", this_player());
            this_player()->move(__DIR__"yongdao1");
        }
        else if(n >=50)
        {
message_vision("ֻ��$Nʹ��ȫ��������������ٿ���ҡҡ�̻̣����������ٲ����档\n", this_player());
           this_player()->move(__DIR__"yongdao1");
        }
        else
        message_vision("ֻ��$N�߸�Ծ�𣬻����Զ��! \n", this_player());
        return 1;

}
int do_plump(string arg)
{
        object ob;
        int new_gin;

        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg!= "down")
        {
            write("��Ҫ��ʲôѽ? \n");
            return 1;
        }
        tell_object(ob,HIR"�㲻��˼�����������������¡�\n"NOR);
        message("visoin",NOR"ֻ��" + ob->query("name") + "�������������¡�\n"NOR,environment(ob), ob);
        if((random((int)ob->query("kar")) <15 ) && ((int)ob->query_skill("dodge",1) < 30) )
        {
            ob->die();
            return 1;
        }
        ob->add("gin",0 - new_gin);
        ob->move(__DIR__"yadi");
        return 1;
}
