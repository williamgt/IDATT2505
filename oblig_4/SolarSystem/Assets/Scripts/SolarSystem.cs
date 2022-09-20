using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SolarSystem : MonoBehaviour
{
    readonly float G = 100f;
    GameObject[] celestials;
    // Start is called before the first frame update
    void Start()
    {
        celestials = GameObject.FindGameObjectsWithTag("Celestial");
        InitialVelocity();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void FixedUpdate()
    {
        Gravity();
    }

    void Gravity()
    {
        foreach(GameObject c1 in celestials)
        {
            foreach(GameObject c2 in celestials)
            {
                if(c1 != c2)
                {
                    float m1 = c1.GetComponent<Rigidbody>().mass;
                    float m2 = c2.GetComponent<Rigidbody>().mass;
                    float r = Vector3.Distance(c1.transform.position, c2.transform.position);

                    c1.GetComponent<Rigidbody>().AddForce((c2.transform.position - c1.transform.position).normalized * (G * (m1 * m2) / (r * r)));
                }
            }
        }
    }

    void InitialVelocity()
    {
        foreach (GameObject c1 in celestials)
        {
            foreach (GameObject c2 in celestials)
            {
                if (c1 != c2)
                {
                    float m2 = c2.GetComponent<Rigidbody>().mass;
                    float r = Vector3.Distance(c1.transform.position, c2.transform.position);
                    c1.transform.LookAt(c2.transform); //c1 facing c2

                    c1.GetComponent<Rigidbody>().velocity += c1.transform.right * Mathf.Sqrt((G * m2) / r);
                }
            }
        }
    }
}
