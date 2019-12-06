//ROOM: /d/yanziwu/shijian.c

inherit ROOM;

string look_muzhuang();
void back(object me);
void init();
int do_jump();
void reset();

void create()
{
        set("short", "�Խ�̨");
        set("long",@LONG
��ʯ����Χ�ɵ�һ��ʯ̨��Ľ�����ҵĵ��Ӿ����ڴ��д��似��̨
�Ƿ��ŵ�ǹ��ꪵ�ʮ�˰������������ˮ���϶�һ�أ���һ�ص�����һ
Щľ׮(muzhuang)��
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "south"  : __DIR__"changlang",
        ]));
        set("item_desc",([
            "muzhuang" : ( :look_muzhuang:),
        ]));
        set("no_clean_up", 0);
        setup();
}

string look_muzhuang()
{
 return "�㶨������������ƽ�������һ��ľ׮��ȴ�ں���������֮�䡣\n"
        "�ٶ࿴һ����������ͷ��Ŀѣ������ԭ������Ľ�������ӵ���\n"
        "����ϰ�Ṧ�ĵط������ǲ���Ҫ����ȥ(jump)һ�������ء�\n";
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump ()
{
    object room;
    object me = this_player () ;

    if( !(room = find_object(__DIR__"muzhuang")) )
            room = load_object(__DIR__"muzhuang");
    if( room = find_object(__DIR__"muzhuang") )
    if((int)room->query_temp("mu_trigger")==1 )
    {
       message_vision("$Nһ���������ľ׮��������������...��Ȼ$N�ַ��˻�������֡�", me) ;
       me -> move( __DIR__"muzhuang");
       me -> move( __DIR__"shijian");
       tell_object(me,"ԭ������ͻȻ�����и���Ӱ��ľ׮�ϻζ����������ǣ�����\n"
                      "Ӳ����һ���������˻�����");
       return 1 ;
    }
    room->set_temp("mu_trigger", 1);
    message_vision("$NһԾ�����ľ׮������˧������ˡ�\n", me );
    me->move(room) ;
    tell_object(me,"\n��һ̤��ľ׮���������������µ������ǲ������г�Х������:\n"
                   "���׺�Ц������������...��\n"  ) ;
    call_out("back", 6 , me );
    room->delete_temp("mu_trigger");
    return 1 ;
}

void back( object me )
{
    int c_exp,c_skill;
    me->move(__DIR__"shijian");
    message_vision("$Nһʽ�������̨��������Χ���˶�����һ����\n",me);
    c_exp=me->query("combat_exp");
    c_skill=me->query_skill("dodge",1);
    me->add("qi",-10);
    me->add("eff_qi",-2);
    if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
    {
        me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
        tell_object(me,"��Ļ����Ṧ������!\n");
    }
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"muzhuang") )
        room->delete("mu_trigger");
}

