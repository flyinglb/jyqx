inherit ROOM;

void create()
{
        int kind=random(6);

        set("short", "���ԭ");

        switch(kind)
        {
        case 0:
                set("long",@LONG
����������Ʈ�Ű��ƣ�ԶԶ��ԭҰ׺��ţ�򣬻��������긲���̲ݣ�����
�����ѳ������ˡ����������ɽ�Ա������Ĳ�ԭ��
long);
        break;
        
        case 1:
                set("long",@LONG
����������Ʈ�Ű��ƣ�ԶԶ��ԭҰ׺��ţ�򣬻��������긲���̲ݣ�����
�����ѳ������ˡ�������������Ա������Ĳ�ԭ��
LONG);
        break;

        case 2:
                set("long",@LONG
����������Ʈ�Ű��ƣ�ԶԶ��ԭҰ׺��ţ�򣬻��������긲���̲ݣ�����
�����ѳ������ˡ�������Ǻ����Ա����ĵĲ�ԭ��
LONG);
        break;

        case 3:
                set("long",@LONG
����������Ʈ�Ű��ƣ�ԶԶ��ԭҰ׺��ţ�򣬻��������긲���̲ݣ�����
�����ѳ������ˡ�������ǳɼ�˼���ķ�����硣
LONG);
        break;

        case 4:
                set("long",@LONG
һ������Ĳ�ԭ��ԶԶ�������ҵ����������������޷��������������Ժ�
�������������ſ���һ���ɹ�����繭Я���ҴҶ�����һƬ��΢�ĳ��̹�ȥ
����Զȥ����������
LONG);
        break;

        default:
                set("long",@LONG
�����ɽ���������춯�ص�������ԭ����������Ұ��񱼶�����������
�������������������ſ����ں���׷�ϣ����д����غ�Х��ʲô����ʱ������
���׵���Ұ������յ�蹤������ǵص���Ⱥ��Ȼ��ڶ�ȥ��
long);
        break;
        }

        set("exits",([
                "east"          :__DIR__"",
                "southeast"     :__DIR__"cy001",
                "south"         :__DIR__"",
                "southwest"     :__DIR__"",
                "west"          :__DIR__"",
                "northwest"     :__DIR__"cy003",
                "north"         :__DIR__"",
                "northeast"     :__DIR__"",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "menggu");
//      set("sleeproom", 1);
        setup();
        replace_program(ROOM);
}
