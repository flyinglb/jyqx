//ROOM daban.c

inherit ROOM;

string look_jingzi();
void create()
{
        set("short","׺����");
        set("long",@LONG
�����ճ���ױ���ĵط�������һ�ź�ľ��ױ̨ �� �����������һ
������ͭ��(jingzi)����ױ̨��ɢ����һЩ��֬���ۡ�̨�԰��Ŷ����
һ����ɻ��ң�����������ˮ�������İ׾ա�
LONG );
        set("exits", ([
            "west" : __DIR__"changl14",
        ]));
        set("item_desc", ([
            "jingzi" : (: look_jingzi :) ,
        ]));
        set("no_clean_up", 0);
        setup();
}

string look_jingzi()
{
	object me=this_player();

	message_vision("$N͵�ۿ��ž��е��Լ���\n",me);	
        if ((string)me->query("gender")=="Ů��")
		return "��̧����������ȥ��ֻ��һ��ò��������Ů������������������㡣\n������һ�ȣ���ɬ�ص�����ͷ�����룺�Ǿ�������\n";
	if ((string)me->query("gender")=="����")
                return "��̧����������ȥ��ֻ��һ��������ֵ������ھ���ֱ�����㡣\n�㲻�����룺������ô����֮�����治����˼�����ˡ�\n";
	if ((string)me->query("gender")=="����")
 		return "��̧����������ȥ��ֻ��һ�����в�Ů����Ӱ��㱾��С�\n�㲻�����룺����Ϊʲô����û����һ��Ů�����أ�\n";
}
