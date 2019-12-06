// zhuangyu.c
inherit NPC;
#include <ansi.h>
int ask_weiwang();

void create()
{
	set_name("ׯ�ʳ�", ({ "zhuang yuncheng", "zhuang","yuncheng" }) );
	set("gender", "����" );
	set("age", 40);
	set("int", 28);
	set("long",
		"���Ǹ�����ʫ�飬ȴ���޲���֮����������\n"
             +"��༭����ʷ���ԡ�������֮�ٸ淢��ȫ�Ҵ��뾩�С�\n" );

	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("noget", "ׯ�ʳ�̾�����Ҳ����ˣ����߰ɡ������ҵ����Ҽ����˰���\n");
	set("chat_chance", 5);
	set("chat_msg", ({
	"\nׯ�ʳ�˵����ֻ���ҵ������ģ������м��˽�Ҷ��������\n"
	"˭�������Ĺ��εļһﾹȻ��ȥ�淢���ҡ���...\n",
	"\nׯ�ʳ�˵����˭Ҫ����֮��ץ��ׯ���ͺ��ˡ�\n",
	"ׯ�ʳ�ͻȻ˵��: ������������Ҫ�������ߴ��кô�����\n",
	"\nׯ�ʳ�̾�˿�����˵������֪�������鷿�����ܣ�ֻ��ϧ�ҳ���ȥ����\n",
	"ׯ�ʳ�˵����˭Ҫ�����ң���һ������֪���Ķ���������\n",
	}));
        set("inquiry", ([
		"����" : "���ݵ��鷿���б�����",
		"�鷿" : "�鷿���Ƿ�������ѧ�ʡ�",
		"��" :  "�ƶ��Ƿ���ʱ�����з���ġ�",
		"����" :  "�ƶ��Ƿ���ʱ�����з���ġ�",
		"����" :  "������һ�£�������һ�¾����ˡ�",
		"����" :  "�ǿɲ������������������ѧ�ʵġ�",
		"��֮��" :  "�����͵�ׯ��ȥ�кô���",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\nׯ�ʳ�˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("ׯ�ʳ���˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}

void init()
{
	object ob; 
	int i;
	ob = this_player();
        if(!userp(ob)) return;
	if(interactive(ob) && !is_fighting() ) 
	say( "ׯ�ʳǹ���Ц�������������������ˣ�\n��λ" + RANK_D->query_respect(ob)
				+ "�������ı����ɲ��ٰ�����Ҫ��ʲô�����׵ģ��������Ұɡ�\n");
	i=(int)this_player()->query("weiwang");
        if(i<20) 
	{
	i=i+10;
        this_player()->set("weiwang",i);
	message_vision(HIC "\n$N�Ľ�����������ˣ�\n" NOR,this_player());
	}
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(i));
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("name") == "��ʷ����") 
	{
	 write(HIC "\nׯ�ʳ�Ц���������н�Ҷ�ӣ��ѵ��㲻֪����\n" NOR);
	 write(HIC "ׯ�ʳ�˵�����Ұ���֮������ץ��ׯ��ȥ�ɣ��Ҳ����ˡ�\n" NOR);		
	 write("ׯ�ʳǴ��˿�������˵��ׯ���ھ��Ƕ����ߡ�\n");
	}		
        return 1;
}

