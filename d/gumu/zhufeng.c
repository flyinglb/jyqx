// zhufeng.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����ɽ����");
        set("long", @LONG
��ʱ������������ɽ���壬��Ұ��Ϊ������������ȥ��Ⱥɽ����
�����ڽ��¡��������Ĵ���������ɽ��������Ө���ԡ�ֻ�����ٵ���
ɢ���ɽ��䣬��ɫ��Ϊ���һ���ʯ (shi)����һ�ԣ��ƺ�����
ʲ�ᶫ�����������ϸ���һ��ɽ·��
LONG
        );
        set("item_desc", ([
                "shi"  :
"
                �����������Ҫ����
                �񴫼������˰麺��
                ���븴Ӣ����࿪־
                �ϵ�֪��ȫ���ɺ���
                ɽ�����������ξ���
                ������������������
                ����ճ˸��칦����
                ������ʱ�����Ȼ��
                ��˻���Բ�������
                ��������������һ��
                ����Ĺ�ݲ���ȥ����
                ������������������
"
        ]));
        set("outdoors", "gumu");
        set("exits", ([
                "westdown"  : __DIR__"shanlu2",
                "southdown" : __DIR__"shanlu1",
        ]));

        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_jump","jump");
}

int do_climb(string arg)
{
        object me = this_player();
        
        if( !arg || (arg!="cliff" && arg!="ya" && arg!="down") )
                return 0;
        
        if( me->query("family/family_name") != "��Ĺ��" 
        || me->query("family/master_name") != "���" )
                return notify_fail("���������±�����ȥ��������ôҲû���ҵ��������İ취��\n");
        
        tell_room(environment(me),me->name()+"һת�������±�����ȥ������\n",({me}));
        tell_object(me,"��˳��ɽ�������������±�����ȥ������\n\n");
        me->move(__DIR__"shibi");
        tell_room(environment(me),me->name()+"���±�����������������\n",({me}));
        return 1;

}

int do_jump(string arg)
{
        object me = this_player();
        string msg1, msg2, msg3, msg4;
        
        if( !arg || (arg!="cliff" && arg!="ya" && arg!="down") )
                return 0;
        
        msg1 = HIY+me->name()+"��֪ΪʲôͻȻ��ɽ����ȥ ����\n"
                + "ֻ����Լ�ƺ�����һ���ҽС���~~~~~~����\n";
                
        msg2 = HIY"�㲻��һ�е���ɽ��һ�� ����\n"
                + "ֻ������ֻ�к����ķ������������������� ����\n"
                + "�㲻���ŵô�� ����~~~~~~����\n"
                + "���������ǰһ�� ����\n\n"NOR;
                
        msg3 = HIY"�㲻��һ�е���ɽ��һ�� ����\n"
                + "ֻ������ֻ�к����ķ������������������� ����\n"
                + "�㲻���ŵô�� ����~~~~~~����\n"
                + "�����������ƺ�������ʲô����һ����ץ ����\n\n"NOR;
                
        msg4 = HIY"�㲻��һ�е���ɽ��һ�� ����\n"
                + "ֻ������ֻ�к����ķ������������������� ����\n"
                + "�㲻������������������Х ~~~~~~��\n"
                + "��Ȼ�����ɵ�һת��һ��ץסɽ�� ����\n\n"NOR;


        if( me->query("family/family_name") != "��Ĺ��" ) {
                tell_room(environment(me),
                msg1 + "���ź���������׹�ص��������ˡ�����\n"
                + "��������һ�ᣬ��ϧʲôҲ�������� ����\n"+NOR
                ,({ me }));
                tell_object(me,msg2);
                me->move(__DIR__"yadi");
                me->die();
                return 1;
        } 
        
        msg1 += "��������һ�ᣬ��ϧʲôҲ�������� ����\n"+NOR;
        
        if( me->query("combat_exp") < 30000 ) {
                tell_room(environment(me), msg1,({me}));
                tell_object(me, msg3);
        } else {
                tell_room(environment(me), msg1,({me}));
                tell_object(me, msg4);
        }
        me->move(__DIR__"shibi");
        tell_room(environment(me),me->name()+"���±������˽���������\n",({me}));
        return 1;
}
