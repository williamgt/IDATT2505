using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MeteoriteTowardsStar : MonoBehaviour
{
    private GameObject star;
    private Renderer r;
    public float speed;
    // Start is called before the first frame update
    void Start()
    {
        star = GameObject.Find("Star");
        r = GetComponent<Renderer>();
    }

    // Update is called once per frame
    void Update()
    {
        if(r.isVisible)
        {
            var step = speed * Time.deltaTime; // calculate distance to move
            transform.position = Vector3.MoveTowards(transform.position, star.transform.position, step);
        }
    }

    void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.tag == "Celestial")
        {
            Debug.Log("Insert explosion here");
            //Destroy(gameObject);
            r.enabled = false;
        }
    }
}
