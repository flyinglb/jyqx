//ROOM: /d/yanziwu/shangyu.c

inherit ROOM;

void init();
int do_jump(string);

void create()
{
        set("short", "����̨");
        set("long",@LONG
վ��̨�ϣ�����Կ���һƬ�ɻ���ǣ���ʱ�м�β����Ծ��ˮ�棬
�е�������������ǰ���·�һ���־Ϳ���ץס��͸����Ҷ��Լ���Կ���
���룬�㲻֪�Ƿ��а���������ȥ��
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "north": __DIR__"shuwu",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;
        int i,jing_cost,qi_cost;
        me=this_player();

        i = (int)me->query_skill("dodge", 0) + random(200);
        jing_cost = 600 / (int)me->query("int");
        qi_cost = 500 / (int)me->query("int");
        if(((int)me->query("jing") < jing_cost) || ((int)me->query("qi") < qi_cost))
               i = 0;

        message_vision("$N����һ������һ��������̨��������ȥ��\n", me);
        me->move(__DIR__"bozhou");
        message_vision("ֻ�����项��һ����$N�ӿ��з���������\n", me);
        if ( i < 40)
        {
                tell_object(me,"��ͻȻ���д�С����á�����ѽ.....");
                me->die();
        }
        else if( i < 80)
              {
                      tell_object(me,"�㰵��һ�������á�.....");
                      me->unconcious();
              }
              else
              {
                      message_vision("$N�����ȵ�վ�ڴ����ϡ�\n", me);
                      me->receive_damage("jing", jing_cost );
                      me->receive_damage("qi", qi_cost );
              }

        return 1;
}
