// Room: /city/wudao.c
// Date: Feb.28 1998 by Java
#include <ansi.h>
inherit ROOM;
string look_gaoshi();
string look_pai();
string  clear_title(string arg);
void add_title(object me,string arg);
void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ǳ�������ʦϯ���߾���̨֮�ϣ��������ߣ���ľ������������ɽ
ӭˬ�����¿���̨��Χ��ͷ�ܶ������Ϸ���һ��Сľ�� (pai)�����������һ
�ź�ֽ��ʾ(gaoshi)��
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
		"pai"    : (: look_pai :),
	]));
	set("exits", ([
		"down"      : __DIR__"leitai",
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	setup();
//	replace_program(ROOM);
}
string look_pai()
{
	return 
"\n
"HIR"start                  "HIY"----  ��̨��֮��ҿ�ʼ���䡣
"HIR"allow    <player id>   "HIY"----  �趨��������̨֮��ҡ�
"HIR"deny     <player id>   "HIY"----  ȡ�������̨�ʸ�
"HIR"load     <player id>   "HIY"----  ���������̨��
"HIR"kick     <player id>   "HIY"----  ���������̨��
"HIR"heal     <player id>   "HIY"----  ����̨����ҾŻ���¶�衣
"HIR"life     <player id>   "HIY"----  �ͱ�ɱ��������ûָ���

"HIG"titles  <player id> 01 "HIY"----  ������������µ�һ (15����)��
"HIG"titles  <player id> 02 "HIY"----  ������������µڶ� (15����)��
"HIG"titles  <player id> 11 "HIY"----  ������������µ�һ (20����)��
"HIG"titles  <player id> 12 "HIY"----  ������������µڶ� (20����)��
"HIG"titles  <player id> 21 "HIY"----  ��������µ�һ���� (30����)��
"HIG"titles  <player id> 22 "HIY"----  ��������µڶ����� (30����)��
"HIG"titles  <player id> 31 "HIY"----  ��������µ�һ���� (40����)��
"HIG"titles  <player id> 32 "HIY"----  ��������µڶ����� (40����)��
"HIG"titles  <player id> 41 "HIY"----  ��������µ�һ���� (40����)��
"HIG"titles  <player id> 42 "HIY"----  ��������µڶ����� (40����)��

\n"NOR;
}
string look_gaoshi()
{
	return 
HIR"\n\n       
                 ��ӹȺ�����ı�����
\n"HIY"
��һ��ÿ�µ�ʮ��������ʮ��ʱ��ʮ�־��б����ᡣ�ص�����������
      ���������
�ڶ���������������飬ÿ�������µ�һ���ڶ��ƺš��������£�
      �׶��� ʮ�ĵ�ʮ���� ������ ʮ������ʮ�� ������ إһ����ʮ��
      ׳���� ئһ����ʮ�� ʢ���� ��ʮ����
      �����һ����ֻ�����ˣ�����ֱ�ӻ�ø����һ��������
����������ʵ����̭�ơ�Ԥ�ȷ�����̭��ÿ��ʵ��������ʤ�ƣ��ֱ��
      ����һ������ȭ�ź͵ڶ���������ʤ�����߽�����һ�֡��׶���
      ����������˾�����ÿ��ֻ��һ����
���ġ�Ϊʹ���µ�һ��ʵ���������ʹ�����������书������perform��
      powerup��enforce��poison�ȡ���roar��������Ӱ���������
      ���л��ʹ�á�Υ��ͣ����
���塢����ʱ���ñ����ͷ���������̨�ϵı�������������ȡ�����о���
      ��ֹʹ�������������ֹʹ�ý�˿�ס���⫼ס���˿�����⣬��
      ֹʹ���˺�������50�ı����簽��ذ�ף����콣����ħ���ȡ�
����������ʱ��ע�����У�����ŭ�ߡ�Υ���ֳ���ʦ�����ߣ�ȡ��һ��
      �����ʸ�

"HIG"                                      ��ӹȺ����  ����
\n"NOR;
}
void init()
{
//	add_action("do_start", "start");
	add_action("do_allow", "allow");
	add_action("do_deny", "deny");
	add_action("do_load", "load");
	add_action("do_kick", "kick");
	add_action("do_heal", "heal");
	add_action("do_life", "life");
	add_action("do_titles", "titles");
}

int do_start()
{
        int i,j;
	object *allob, ob, me;

        allob = users();
        me = this_object();
        ob = this_player();

        j = 0;
        for ( i=sizeof(allob); i>0; i-- ) {
             if (environment(allob[i-1]) ->query("short") =="��̨") {
                if (j == 0) {
                    me = allob[i-1];
                    j = 1;
                }
                else ob = allob[i-1]; 
             }
        }
        if (ob != this_player()) me->fight_ob(ob);
        return 1;
}
int do_allow(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: allow <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N�趨��"+ob->name()+"����̨��\n"NOR, me);
	ob -> set_temp("leitai_allow",1);
	ob -> delete("env/combatd");
	tell_object(ob,HIR"\n��������̨�ˡ�\n"NOR);
	return 1;
}
int do_deny(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: deny <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N�趨��"+ob->name()+"����ʱ������̨��\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n�Ȳ�������̨�˰ɡ�\n"NOR);
	return 1;
}
int do_load(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: loadup <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"����̨��\n"NOR, me);
	message_vision(HIG"$N˫��һ�ţ��ڿն�������������̨���ϣ����ǽ�磬ʮ��������\n"NOR, ob);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n��ʲô��ѽ�㣬�������ɸ��ҡ�\n"NOR);
	ob -> move("/d/city/leitai");
	ob -> delete_temp("view_leitai");
	ob -> delete("env/combatd");
	message_vision(HIG"$N�ڿ�������̨���ϣ����ǽ�磬ʮ��������\n"NOR, ob);
	return 1;
}
int do_kick(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: kickdown <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"������̨��\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	message_vision(HIG"ֻ����$N໵�һ��������������̨ȥ�ˡ�\n"NOR, ob);
	tell_object(ob,HIR"\nû�湻��������ȥ������ҡ�\n"NOR);
	ob -> move("/d/city/wudao1");
	ob -> set_temp("view_leitai",1);
	message_vision(HIG"ֻ��$N�������У�һ����ƨ�ɶ����ڵ��ϰ���������\n"NOR, ob);
	return 1;
}
int do_heal(string arg)
{
	object ob, me, obj;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: heal <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"һ���Ż���¶�衣\n"NOR, me);
	obj = new("/clone/misc/jiuhua");
	obj -> move(ob); 
	tell_object(ob,HIR"\n����һ���Ż���¶��ָ�������\n"NOR);
	return 1;
}
int do_life(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: reback <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"�����ûָ���ʧ��\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n���������ã�������ͻ�ָ��ġ�\n"NOR);
	ob -> move("/d/death/god2");
	ob -> delete_temp("view_leitai");
	return 1;
}
int do_titles(string arg)
{
	object obj, me=this_player();
	string dest, topic;

	if( !arg || sscanf(arg, "%s %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�ƺţ�\n");
	obj = find_player(dest);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	switch (topic)
	{
		case "01": add_title(obj, "�������µ�һ"); break;
		case "02": add_title(obj, "�������µڶ�"); break;
		case "11": add_title(obj, "�������µ�һ"); break;
		case "12": add_title(obj, "�������µڶ�"); break;
		case "21": add_title(obj, "���µ�һ����"); break;
		case "22": add_title(obj, "���µڶ�����"); break;
		case "31": add_title(obj, "���µ�һ����"); break;
		case "32": add_title(obj, "���µڶ�����"); break;
		case "41": add_title(obj, "���µ�һ����"); break;
		case "42": add_title(obj, "���µڶ�����"); break;
		default: break;
	}
	message_vision(HIG"$N��"+obj->name()+"��š�\n"NOR, me);
	return 1;
}
void add_title(object me,string arg)
{
        string title;
        title= arg + clear_title((string)me->query("title"));
        me->set("title",title);
}
string clear_title(string arg)
{
        if( !arg ) return "";
        if( (strsrch(arg, "�������µ�һ") >= 0) ||
            (strsrch(arg, "�������µڶ�") >= 0) ||
            (strsrch(arg, "�������µ�һ") >= 0) ||
            (strsrch(arg, "�������µڶ�") >= 0) ||
            (strsrch(arg, "���µ�һ����") >= 0) ||
            (strsrch(arg, "���µڶ�����") >= 0) ||
            (strsrch(arg, "���µ�һ����") >= 0) ||
            (strsrch(arg, "���µڶ�����") >= 0) ||
            (strsrch(arg, "���µ�һ����") >= 0) ||
            (strsrch(arg, "���µڶ�����") >= 0))
                {
                arg = replace_string(arg, "�������µ�һ","");
                arg = replace_string(arg, "�������µڶ�","");
                arg = replace_string(arg, "�������µ�һ","");
                arg = replace_string(arg, "�������µڶ�","");
                arg = replace_string(arg, "���µ�һ����","");
                arg = replace_string(arg, "���µڶ�����","");
                arg = replace_string(arg, "���µ�һ����","");
                arg = replace_string(arg, "���µڶ�����","");
                arg = replace_string(arg, "���µ�һ����","");
                arg = replace_string(arg, "���µڶ�����","");
        }
        return arg;
}
