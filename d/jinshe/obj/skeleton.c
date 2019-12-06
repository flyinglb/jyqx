// skeleton.c

inherit ITEM;

void create()
{
	set_name("����", ({ "skeleton" }) );
	set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
	set("unit", "��" );
	set("big_count", 1);
	set("small_count", 1);
}
void init()
{
	add_action("do_mai", "mai");
	add_action("do_mai", "bury");
}
int do_mai(string arg)
{
        int n;
        object ob, me = this_player();

        n = this_player()->query("neili");
        if( !arg || arg != "skeleton")
        {
                write("��Ҫ��ʲô? \n");
                return 1;
        }
        if (me->query_temp("marks/jinshe") == "1")
        {
                if (n > 200 && query("small_count") == 1)
                {
                        message_vision(
"$N��������ھ���������ϼᣬʱʱ����ɽʯ���ھ�ԶΪ������
�����ֽ��������ߣ���Ȼ����һ������ͷ������һ�����������
��Ȼ����һֻ���С�\n", me);
                        ob = new(__DIR__"smallbox");
                        ob->move(environment(me));
                        me->set_temp("marks/jinshe", "2");
                        add("small_count", -1);
                }
                else
                {
                        message_vision("$N�ڲ���ʲô�����˼��¾Ͳ�����ˡ�\n", me);
                        me->set("neili",0);
                }
        }
        else
        {
                if (n > 100 && query("big_count") == 1)
                {
                        message_vision(
"$N���ֵ��������ģ�������������������$N����һ�ᣬ��Ȼ��
��һ��������һ���������ƽ����һ�����������п����壬����
���˼��£������Ա�������ԭ������һֻ���߼����Ĵ����С�\n", me);
                        ob = new(__DIR__"bigbox");
                        ob->move(environment(me));
                        me->set_temp("marks/jinshe", "1");
                        add("big_count", -1);
                }
                else
                {
                        message_vision("$N�ڲ���ʲô�����˼��¾Ͳ�����ˡ�\n", me);
                        me->set("neili",0);
                }
        }
        return 1;
}

