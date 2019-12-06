// /u/beyond/mr/obj/shu1.c
// this is made by beyond
// update 1997.6.29

inherit ITEM;

string* titles = ({
	"��ת�����ؼ�",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "douzhuan xingyi", "shu", "book" }));    
	set("long", "
��ת���Ƴ����׶��ж����鼴�ɡ�
��ת���Ƶڶ��׶��ж�ͼ�⼴�ɡ�
��ת���Ƶ����׶������ֻ����ɡ�
��ת���Ƶ��Ľ׶��ڻ�ʩˮ���ж������书�ؼ��������򼴿ɡ�
");
	set_weight(200);       
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����Ľ���ķ����¾�\n");
		set("value", 500);
		set("material", "paper");
		set("no_drop",1);
	        set("no_get",1);

	}
}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}    
int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
//        object ob;
//        mapping skill;
        int dzlevel; 
        int neili_lost;
        if (!(arg=="douzhuan xingyi" ||arg=="book" || arg=="shu"))
        return 0;

        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (!id(arg)) {	
                write("��Ҫ��ʲô��\n");
                return 1;
        }
       
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if( (int)me->query("jing") < 15 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
	if (me->query_skill("douzhuan-xingyi",1)>(me->query_skill("parry",1)+10)){
		write("������Ļ����мܵĻ����������ٽ��и���һ�����ߡ�\n");
		return 1;
	}
	if( (int)me->query("neili") < neili_lost) {
		write("�������������޷�������ô������书��\n");
                return 1;
        }

        dzlevel = me->query_skill("douzhuan-xingyi", 1);
        if( (int)me->query("combat_exp") < (int)dzlevel*dzlevel*dzlevel/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }
	 
	if ( me->query_skill("douzhuan-xignyi", 1) < 30) {
		neili_lost = 5;
		me->receive_damage("jing", 15);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("douzhuan-xingyi", (int)me->query_skill("parry", 1)/3+1);
		write("��������ϰ��ת���Ƶ��书�ؼ����ƺ��е��ĵá�\n");
		return 1;
	}
	return 1;
}

