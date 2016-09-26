using UnityEngine;
using System.Collections;
using UnityEditor;

[CustomEditor(typeof(InventoryListCreator))]
public class InventoryEditor : Editor
{
    public static bool[] foldout = new bool[100];
    public override void OnInspectorGUI()
    {
        InventoryListCreator t = (InventoryListCreator)target;

        base.OnInspectorGUI();

        for (int i = 0; i < t.Inventory.Count; ++i) 
        {
            Editor e = CreateEditor(t.Inventory[i], null);
            foldout[i] = EditorGUILayout.Foldout(foldout[i], t.Inventory[i].itemName);

            if (foldout[i])
                e.OnInspectorGUI();          
        }

        EditorUtility.SetDirty(target);
    }
}
