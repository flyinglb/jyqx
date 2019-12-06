// yadi.c �µ�

inherit ROOM;

int do_climb(string arg);
int do_swim(string arg);
int do_push(string arg);

void create()
{
        set("short", "�µ�");
        set("long", @LONG
��������¹ȵ����ˣ�������������һ����Ȼ�ĺ�������������
���ף�����ȫ��ˮ(water)����ʱ�м���������С���������ι�����
�沢�����Գ��ڡ�
LONG );
        set("item_desc",([
            "water" : "���̱��̵�ˮ����������ҫ���������ˣ��㲻������Ӿ�ˡ�\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_climb","climb");
        add_action("do_push","push");
        add_action("do_swim","swim");
}
int do_push(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg != "men")
        {
                write("������ʲôѽ? \n");
                return 1;
        }
        if(!this_player()->query_temp("yadi_swim"))
        {
                write("������ʲôѽ? \n");
                return 1;
        }
        else
                this_player()->delete_temp("yadi_swim");

        message_vision("$N��������һ����������ץסʯ�ŵ�һ�ࡣ\n", this_player());
        if (n >150)
        {
                message_vision("ֻ��$Nһ�˵�������˫��һʹ����ʯ�ž������Ŀ��ˡ�\n", this_player());
                set("exits/west",__DIR__"shidong9");
                this_player()->set("neili",n-150);
                remove_call_out("close");
                call_out("close",5, this_object());
        }
        else
        {
                message_vision("$Nʹ����ȫ�������ʯ��ȴ��˿û����\n", this_player());
                this_player()->set("neili",0);
        }
        return 1;
}

void close(object room)
{
        message("vision","ʯ���Զ��ĺ����ˡ�\n", room);
        room->delete("exits/west");
}

int do_swim(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg != "water")
        {
                write("�����ʲôѽ?\n");
                return 1;
        }
        this_player()->set_temp("yadi_swim",1);
        message_vision("$N������һ����������������������\n", me);
        if (random((int)me->query("kar")) >10)
        {
                message_vision("���������ţ�ͻȻ������һ��ʯ��(men)��Ҳ�����ܽ�����(push)����\n", me);
                me->receive_damage("qi", 15);
                me->receive_wound("qi", 10);
        }
        else
        {
                message_vision("���������ţ�ͻȻ������һ������(suo)���������˹��������������������⣬���ܾ���������������(climb)��\n", me);
                me->receive_damage("qi",10);
                me->receive_wound("qi",10);
        }
        return 1;
}

int do_climb(string arg)
{
        int n;
        n = this_player()->query_skill("dodge",1);
        if ( !arg || arg != "suo")
        {
                write("��Ҫ��ʲôѽ? \n");
                return 1;
        }
        message_vision("$N������һ����������������������������\n", this_player());
        if(n >40)
        {
                message_vision("$N���˰��죬��������������$N��������ǰ˫�ƺ�ʮ����л���档\n", this_player());
                this_player()->move(__DIR__"pubu");
        }
        else
        {
                message_vision("$N����һ�ᣬ̫���ˣ���С�Ļ�����������!û�취��
���������ɡ�\n", this_player());
                this_player()->receive_damage("qi",15);
                this_player()->receive_wound("qi",10);
        }
        return 1;
}
